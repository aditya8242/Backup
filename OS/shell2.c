#include<stdio.h>      // for printf(), scanf(), fgets()
#include<stdlib.h>     // for exit(), general utilities
#include<string.h>     // for strcmp(), strtok()
#include<unistd.h>     // for fork(), execvp()
#include<sys/types.h>  // for pid_t and process control types
#include<sys/wait.h>   // for wait()
#include<dirent.h>     // for directory handling: opendir(), readdir(), closedir()

int main()
{
    char input[100], *args[10];
    char *token;
    int i;

    while(1)
    {
        printf("myshell$ ");     // shell prompt
        fflush(stdout);          // make sure prompt appears immediately

        // read user input
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = '\0'; // remove newline

        // exit shell
        if(strcmp(input, "exit") == 0)
            break;

        // tokenize command
        i = 0;
        token = strtok(input, " ");
        while(token != NULL)
        {
            args[i++] = token;
            token = strtok(NULL, " ");
        }
        args[i] = NULL;   // execvp() needs a NULL terminator

        // skip empty input
        if(args[0] == NULL)
            continue;

        // custom "list" command
        if(strcmp(args[0], "list") == 0)
        {
            if(args[1] == NULL || args[2] == NULL)
            {
                printf("Usage: list f <dirname> OR list i <dirname>\n");
                continue;
            }

            DIR *dir;                 // directory pointer
            struct dirent *entry;     // to read directory entries
            dir = opendir(args[2]);   // open the directory

            if(dir == NULL)
            {
                printf("Cannot open directory %s\n", args[2]);
                continue;
            }

            // list file names only
            if(strcmp(args[1], "f") == 0)
            {
                while((entry = readdir(dir)) != NULL)
                {
                    if(strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0)
                        printf("%s\n", entry->d_name);
                }
            }
            // list file names with inode numbers
            else if(strcmp(args[1], "i") == 0)
            {
                while((entry = readdir(dir)) != NULL)
                {
                    if(strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0)
                        printf("%s\t%lu\n", entry->d_name, entry->d_ino);  // %lu for inode
                }
            }
            else
            {
                printf("Invalid option. Use f or i.\n");
            }

            closedir(dir);  // always close directory
        }
        else
        {
            // for all other system commands
            pid_t pid = fork();  // create a child process

            if(pid == 0)
            {
                execvp(args[0], args);  // replace child with command
                printf("Command not found: %s\n", args[0]); // if exec fails
                exit(1);
            }
            else if(pid > 0)
            {
                wait(NULL); // parent waits for child to finish
            }
            else
            {
                printf("Fork failed.\n");
            }
        }
    }

    return 0;
}
