#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <errno.h>
#include <time.h>

void myvechandler (int sig)
{
//printf("Signal needs to be handled here");


    int count=0;

    if (sig == SIGALRM)
    {
    
        alarm(10);
        count=count+10;
        printf("Tick: %d",count);
       
            
    }
    
    
}


int main()
{

    struct sigvec mysigvec;
    mysigvec.sv_flags=0;
    mysigvec.sv_handler=myvechandler;
    
    
    sigvec(SIGALRM,&mysigvec,NULL);
    sigvec(SIGINT,&mysigvec,NULL);
    sigvec(SIGTERM,&mysigvec,NULL);
    sigvec(SIGTSTP,&mysigvec,NULL);
    
    
   // int i=1;
    
   // if (i==1)
    //{
   // sleep(10);
   // }
            
    
}

  