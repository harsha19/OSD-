#include <stdio.h>
#include <time.h>
#include <unistd.h> /* For executing exec commands */
#include <sys/types.h> /*  For handling different data types*/
#include <stdlib.h>

int main (int argc, char *argv[2])

{
	/* We are using clock_t datatype to save a process CPU time in clock ticks  using clock() function 
	Declare in the header file time.h  */

	clock_t starttime,endtime;
	int tottime; 
	pid_t pid;
	pid=fork();
	starttime = clock();
	
	printf("\n  My first program in OSD Class");
	
	if (pid<0)
	{
		fprintf(stderr, "Fork Failed"); return 1;
	}

	else if (pid == 0) 
	{ /* child process */
		system(argv[1]);
	}
	else 
	{ /* parent process */
          /* parent will wait for the child to complete */
          wait(NULL);
          printf("\n Child Complete \n");
	}
	endtime = clock();

	tottime=endtime-starttime;
	printf("Time taken %d  clicks (%f seconds) ",tottime,((float)tottime)/CLOCKS_PER_SEC);

return 0;

}



