#include <stdio.h>
#include <sys/types.h>
#include <sys/time.h>                
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>


#define MD 1

#define bs 65536


int main ( int argc, char *argv[] )
{
	char data[bs];
	printf("File Size - %d\n",bs);
	if(!MD)
		printf("Using open, read, write, close\n");
	else
		printf("Using fopen, fread, fwrite, fclose\n");	
	if(!MD)
	{
		int fd = 0,fr = 0;
		fd = open("/dev/urandom",O_RDONLY);
		if(fd == -1)
		{
			printf("\n open() failed with error [%s]\n",strerror(errno));
			return 1;
		}
		else
		{
			int i = 0;
			struct timeval t1, t2;
			double elapsedTime;
			char cbuf[100];

			for(i=0;i<10;i++)
			if(read(fd,data,bs) != -1)  
			{
				sprintf(cbuf,"%s%d","/tmp/new",i);
				fr = open(cbuf,O_CREAT|O_RDWR);
				gettimeofday(&t1, NULL);
				if( write(fr,data,bs) == -1) 
					printf("write error\n");

				gettimeofday(&t2, NULL);

				elapsedTime = (t2.tv_sec - t1.tv_sec) * 1000.0;      
				elapsedTime += (t2.tv_usec - t1.tv_usec) / 1000.0;	
				printf("Time Taken = %0.4f MilliSecond \n",elapsedTime);

				close(fr);
			}
			else
			{
				printf("read error\n");
			}
			close(fd);
		}
	}
	else
	{
		int fd = 0;
		FILE *fr = 0;
		fd = open("/dev/urandom",O_RDONLY);
		if(fd == -1)
		{
			printf("\n open() failed with error [%s]\n",strerror(errno));
			return 1;
		}
		else
		{
			int i = 0;
			struct timeval t1, t2;
			double elapsedTime;
			char cbuf[100];

			for(i=0;i<10;i++)
			if(read(fd,data,bs) != -1)  
			{
				sprintf(cbuf,"%s%d","/tmp/new",i);
				fr = fopen(cbuf,"w");
				gettimeofday(&t1, NULL);
				if( fwrite(data,1,bs,fr) == -1) 
					printf("write error\n");
				gettimeofday(&t2, NULL);
				elapsedTime = (t2.tv_sec - t1.tv_sec) * 1000.0;
				elapsedTime += (t2.tv_usec - t1.tv_usec) / 1000.0;	
				printf("Time Taken = %0.4f MilliSecond \n",elapsedTime);
				fclose(fr);
			}
			else
			{
				printf("read error\n");
			}
			close(fd);
		}

	}
	return 0;
}
