#include<stdio.h>      // for printf(), scanf(), fgets(), etc.
#include<stdlib.h>     // for exit(), system utilities, etc.
#include<string.h>     // for strcmp(), strtok(), strlen(), etc.
#include<unistd.h>     // for fork(), execvp(), getpid(), etc.
#include<sys/types.h>  // for pid_t and process control data types
#include<sys/wait.h>   // for wait(), lets parent wait for child
#include<dirent.h>     // for directory handling: opendir(), readdir(), closedir()

int main()
{
    char input[100], *args[10];
    char *token;
    int i;

    while(1)
    {
        printf("myshell$ ");      // custom shell prompt
        fflush(stdout);           // flush output buffer so prompt appears immediately

        // get full input line from user
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = '\0'; // remove newline at end of input

        // check for exit command
        if(strcmp(input, "exit") == 0)
            break;

        // tokenize input string into command and arguments
        i = 0;
        token = strtok(input, " ");
        while(token != NULL)
        {
            args[i++] = token;
            token = strtok(NULL, " ");
        }
        args[i] = NULL;   // execvp() expects last argument as NULL

        // skip if user just pressed Enter
        if(args[0] == NULL)
            continue;

        // custom "list" command
        if(strcmp(args[0], "list") == 0)
        {
            if(args[1] == NULL || args[2] == NULL)
            {
                printf("Usage: list f <dirname> OR list n <dirname>\n");
                continue;
            }

            DIR *dir;                // directory pointer
            struct dirent *entry;    // structure to store directory entries
            dir = opendir(args[2]);  // open the given directory

            if(dir == NULL)
            {
                printf("Cannot open directory %s\n", args[2]);
                continue;
            }

            // option 'f' → print file names
            if(strcmp(args[1], "f") == 0)
            {
                while((entry = readdir(dir)) != NULL)
                {
                    // skip current (.) and parent (..) entries
                    if(strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0)
                        printf("%s\n", entry->d_name);
                }
            }
            // option 'n' → print number of files
            else if(strcmp(args[1], "n") == 0)
            {
                int count = 0;
                while((entry = readdir(dir)) != NULL)
                {
                    if(strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0)
                        count++;
                }
                printf("%d\n", count);
            }
            else
            {
                printf("Invalid option. Use f or n.\n");
            }

            closedir(dir); // close directory after use
        }
        else
        {
            // for other commands like ls, pwd, date, etc.
            pid_t pid = fork();  // create a new process

            if(pid == 0)
            {
                // child process executes the given command
                execvp(args[0], args);
                // only runs if execvp fails
                printf("Command not found: %s\n", args[0]);
                exit(1);
            }
            else if(pid > 0)
            {
                // parent process waits until child finishes
                wait(NULL);
            }
            else
            {
                // fork failed
                printf("Fork failed.\n");
            }
        }
    }

    return 0;
}