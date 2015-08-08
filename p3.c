#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <errno.h>
#include <time.h>

char samp='c';
clock_t start,end;
double timetaken;

void myvechandler (int sig)
{

    if (sig == SIGALRM)
    {
        int count=0;
        count=count+10;
        printf("Tick: %d",count);
        printf("Hi this is signal handler");
        return;
            
    }
    

    if (sig == SIGINT)
    {
        printf("Interrupt is called");
        printf("time taken: %f", timetaken);
        return;

    }

    if (sig == SIGTERM)
    {
        printf("Interrupt is called");
        printf("time taken: %f", timetaken);
        exit(EXIT_SUCCESS);
    }
    
    if (sig == SIGTSTP)
    {
        int j;

        for (j=0;j<10;j++)
        {
        printf("user inputs:%c", samp);
        }

    }
    
}


int main()
{

    
    start=clock();
    struct sigvec mysigvec;
    mysigvec.sv_flags=0;
    mysigvec.sv_handler=myvechandler;
    
    
    sigvec(SIGALRM,&mysigvec,NULL);
    sigvec(SIGINT,&mysigvec,NULL);
    sigvec(SIGTERM,&mysigvec,NULL);
    sigvec(SIGTSTP,&mysigvec,NULL);
    
    //pause();
    sleep(5);

    sigvec(SIGALRM,&mysigvec,NULL);
    
    end=clock();
    timetaken=end-start;


}
