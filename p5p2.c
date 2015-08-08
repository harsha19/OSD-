#include <sys/stat.h>
#include <fcntl.h>
/*#define MAX_READ 10,000,000 */
#include <unistd.h>            
#include <stdio.h>
#include <stdlib.h>


int main()

{

	
	{
		int inputfdur,inputfdnull;

		ssize_t readfd,writefd;
		ssize_t tenmb=10485760;

		int i;
		int * holder;


		inputfdur=open("/dev/urandom" ,O_RDONLY );
		inputfdnull=open("/dev/null" ,O_RDONLY );

		

        holder=(int *) malloc (tenmb);
        readfd=read(inputfdur,holder,10000000);
        writefd=write(inputfdnull,holder,10000000);

        if (writefd==-1)
        	errExit("write");
        else
        printf("The size is %lu",sizeof(holder));

        fprintf(stdout," The input data buffer is : %d \n ", *holder);

       	return 1;


	}
	
}