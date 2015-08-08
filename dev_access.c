#include <sys/stat.h>
#include <fcntl.h>
#define MAX_READ 10
#include <unistd.h>            
#include <stdio.h>
#include <time.h>
#include <stdlib.h>


int main()

{


	printf("1.Enter 1 for using  mouse0: \n");
	printf("2. Enter 2 for using urandom:\n");

	int opt;
	scanf("%d",&opt);
	switch (opt)
	{
		case 1: 
		do
		{
			int inputfd;

			size_t readfd;

			int buffer[MAX_READ];

			inputfd=open("/dev/input/mouse0" ,O_RDONLY );
		/*if (inputfd == -1)
                   errExit("open");
                   */

        	readfd=read(inputfd,buffer,MAX_READ);

        	fprintf(stdout," The input data buffer is : %d \n ", *buffer);

		}
	while (1);

		case 2:


		{
		int inputfdur,inputfdnull;

		ssize_t readfd,writefd;
		ssize_t tenmb=10485760; /* 10 MB in bytes */

		int i;
		int * holder;
		double gettime;
		inputfdur=open("/dev/urandom" ,O_RDONLY );
		inputfdnull=open("/dev/null" ,O_RDONLY );

        holder=(int *) malloc (tenmb);

        clock_t start,end;
        start =clock();
        readfd=read(inputfdur,holder,10000000);
        writefd=write(inputfdnull,holder,10000000);

        /*if (writefd==-1)
        	errExit("write");
        else */
        printf("The size is %lu",sizeof(holder));
        fprintf(stdout," The input data buffer is : %d \n ", *holder); /* printing ins stdout through fprintf function */
        end =clock();
		gettime=((double)(end-start));
		printf("elapsed time is:%f",gettime);
       	return 1;


		}
	}
	
}