//
//  sigaction.c
//  
//  Author Prince Uppal
//  Created on 17 April, 2014
//

#include <unistd.h>
#include <signal.h>
#include <stdio.h>
#include <time.h>

void singHandler( int sig ) 
{
    printf( " Signal count %d\n", sig );
}

int main( ) 
 {

    struct sigaction sact;
    
    if(sigemptyset( &sact.sa_mask )<0)
    {
    sact.sa_flags = 0;
    }
    sact.sa_handler = singHandler;
    sigaction( SIGALRM, &sact, NULL );
    
    alarm( 3 );
    
       
    //before pause
    time_t timeBefore;
    
    time(&timeBefore);
    printf( "Process is about to pause, Current time is %s\n", ctime(&timeBefore) );
    pause();
    
 
    //after pause
    time_t timeAfter;
    
    time(&timeAfter);
    printf( " Pausing time: %s\n", ctime(&timeAfter) );
    
    
    return( 0 );
}

