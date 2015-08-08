#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <sys/wait.h>
#include <stdlib.h>
int main()
{

clock_t start,end;
int  total_time;
int num,i;
int temp=0;

start=clock();

printf("enter any number");
scanf("%d",&num);

int pid;
pid=fork();
if(pid<0)
{
fprintf(stderr,"fork failed");
return 1; 
}        
else if(pid==0)
{        
    for( i=1;i<=10;i++)
{
printf("\t %d x %d = %d \n",num,i,num*i);
}     
{
execlp("/bin/ls","ls",NULL);
}   
//execlp('/bin/ls',"ls",NULL); 
}   
else
{
wait(NULL); 
}   
sleep(10); 
end=clock(); 
total_time=(end-start);
printf("/difference in times is:%f",((float)total_time));
return 0;
}
