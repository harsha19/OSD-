#include <unistd.h>
#include <signal.h>
#include <stdio.h>
#include <sys/time.h>
#include <string.h>

void mysighandler (int sig)
{
	printf("signal caught");  /* UN SAFE */
}

void timerhandler (int signum)
{

}

int main()
{

	struct sigaction isacst;
	struct itimerval timer;

	isacst.sa_flags=0;
	isacst.sa_handler=mysighandler;

  	timer.it_value.tv_sec = 3; 
  	timer.it_value.tv_usec = 0; 

  	timer.it_interval.tv_sec = 0; 
  	timer.it_interval.tv_usec = 0; 

  	setitimer(ITIMER_REAL, &timer, NULL );
  	pause();
	sigaction(SIGALRM,&isacst,NULL );
	
}