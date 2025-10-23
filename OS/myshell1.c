#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/wait.h>
#include<sys/types.h>
#include<dirent.h>

int main()
{
	char input[100], *args[10];		// user input
	char *tokens;		// for tokens
	int i = 0;				// counter

	while(1)
	{
		printf("$myshell ");
		fflush(stdout);		// make sure prompt appears immediately

		fgets(input, sizeof(input), stdin); // input
		input[strcspn(input,"\n")] = '\0'; // remove newline

		// exit
		if(strcmp(input, "exit") == 0)
		{
			break;
		}

		// tokenize
		i = 0;
		tokens = strtok(input, " ");
		while(tokens != NULL)
		{
			args[i++] = tokens;
			tokens = strtok(NULL, " ");
		}
		args[i] = NULL; // execvp requires NULL

		// important
		if(args[0] == NULL)
			continue;

		// list
		if(strcmp(args[0], "list")==0)
		{
			if(args[1] == NULL || args[2] == NULL)
			{
				printf("Usage: list -f/-i directory_name\n");
				continue;
			}

			DIR *dir;	// pointer
			struct dirent *entry;	
			dir = opendir(args[2]);

			if(dir = NULL)
			{
				printf("Unable to open directory");
			}

			if(strcmp(args[1], "f"))
			{
				while((entry = readdir(dir)) != NULL)
				{
					if(strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0)
					{
						printf("%s\n", entry->d_name);
					}
				}
			}
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
			pid_t pid;

			pid = fork();

			if(pid == 0)
			{
				execvp(args[0], args);
				printf("Command not found: %s\n", args[0]);
				exit(1);
			}
			else if(pid > 0)
			{
				wait(NULL);
			}
			else
			{
				printf("Fork failed");
			}
		}
	}
	return 0;
}