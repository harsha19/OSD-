#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#define MAX 100
int main()
{
int argo, argc, ret, status;
pid_t pid;
pid_t pid1;
char input[MAX], *argp[MAX], cwd[MAX],  *argv[MAX], *cn, *r, *cs, *cp;
const char *delim = " \t\n";
const char *sep = ">";
while (1) 
{
	printf("rahul prompt:- \t");    
	//to read input
	r=fgets(input, sizeof(input), stdin);
	if(r!= NULL) 
		{
			cp = input;
			cs = input;
			//to search for redirection symbol and token the string
				for (argo = 0; argo < MAX; argo++)
					{
						if ((argp[argo] = strtok(cs,sep)) == NULL)
						break;
						cs = NULL;
					}
				if(argp[1] == NULL)
					{
						for (argc = 0; argc < MAX; argc++) 
							{
							if ((argv[argc] = strtok(cp,delim)) == NULL)
							break;
							cp = NULL;
							}
							//to exit the prompt
						if(strcmp(argv[0], "exit") == 0) 
						{
						exit(0);
						}
						else if(strcmp(argv[0], "cd") != 0)
						{
						pid = fork();
							if(pid == 0) //child
									{
										//to execute the commands in argument vector
											execvp(argv[0], argv);
									} 
							else
									{
											wait(&status);
									}
						}
//to change directory
		else if (getcwd(cwd, sizeof(cwd)) != NULL)
				{
					printf( "previous directory: %s\n", cwd);
					ret = chdir(argv[1]);
					if(getcwd(cwd,sizeof(cwd))!=NULL)
					printf("current directory: %s\n",cwd);
					else perror("getcwd error\n");
				} 
				else 
					perror("error");
	}
//to redirecting
			else if(argp[1] != NULL)
			{
				cp = argp[0];
				cn = argp[1];
				for(argc = 0; argc < MAX; argc++)
					{
						if((argv[argc]=strtok(cp,delim)) == NULL)
						break;
						cp = NULL;
					}
						pid_t pid1 = fork();
			if(pid1 == 0)
					{
						int fd = open("divgan123", O_RDWR | O_CREAT, S_IRUSR | S_IWUSR);
						dup2(fd,1);
						execvp(argv[0], argv);
						close(fd);
					}
				else
					{
						wait(&status);
					}
			}
		}
}
return(0);
}
