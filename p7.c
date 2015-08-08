#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

int main()
{
    size_t actuwrit,mentionedwrit;
    char *buf[100];
    float a[6]={2,16,128,1024,8192,65536};
    int fd;
    fd=open("/tmp",O_WRONLY);
    int i=0;
    
    do
        {
        	/* code */
        	actuwrit=write(fd,*buf, a[i]);
        	i++;
        	printf("Fd is %d\n",fd );
        } while (i<=9);    

        
    
}
