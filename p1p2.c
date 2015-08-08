#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <errno.h>
#include <time.h>


void sigHandler( int sig ) 
{
    printf( "Catch Signals: %d\n", sig );
}
int main()
{
struct sigaction sigact,old_action;
sigemptyset(&sigact.sa_mask);
sigact.sa_flags = 0;
sigact.sa_handler = sigHandler;

if (sigaction(SIGALRM,&sigact,NULL)==-1) 
{
		perror( "sigaction");
	pause();	/* wait for signal interruption */
     //printf("%s sigaction exits\n"); 

}
		 sigaction( SIGALRM, &sigact, NULL );
		alarm( 5 );
    
       
    
    time_t timeBefore;
    
    time(&timeBefore);
    printf( "time just before the process gets stopped:\n running time is %s\n", ctime(&timeBefore) );
    pause();
    
 
    
    time_t timeAfter;
    
    time(&timeAfter);
    printf( "time the process resumes: %s\n", ctime(&timeAfter) );
    
      return( 0 );
}
