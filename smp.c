/*sravan kumar karpurapu*/
/*netid: yv9778*/
/*assignment2*/

#include <stdlib.h>
#include <stdio.h>
int ferry,carparking,waitingcars,parcapacity=100,leavingcars;
main(){
      int a,c=1;
            if(c){
                    printf("Menu for Car Parking\n" ) ;
                    printf("1. No.of car Arrived\n" ) ;
                    printf("2. No.of car available at parking lot \n");
                    printf("3. Total space Available for car at parking lot \n");
                    printf("4. No.of Cars Leaving from Parking lot \n");
                    printf("5. Exit \n");
                    printf("enter your choice from menu \n");
                    scanf("%d",&a);
                    
                switch(a){
                          case 1:
                                  printf("Enter the no of cars waiting to park in lot: \n");
                                  scanf("%d",&waitingcars);
                                  ferry+=waitingcars;
                                  waitingcars=0; 
                                  if(ferry<=parcapacity)
                                  {
                                  addcars(1);
                                  carparking+=ferry;
                                  parcapacity-=ferry;
                                  ferry=0;
                                                                
                                  }
                                  else{
                                       if(ferry>=parcapacity && parcapacity!=0){
                                                       printf("Space available in parking lot is %d:  \n",parcapacity);
                                                       printf("farry takes car less then that \n");
                                                       ferry=0;
                                                       }
                                       else{
                                       printf("There is no space in parking lot \n");
                                       }
                                       }
                                   
                          case 2:
                                 printf(" Number of cars present on parking lot are :  %d \n",carparking);
                                                                  
                          case 3:
                                 printf("Space Available for cars to park in parking lot is: %d \n",parcapacity);
                                 
                                 
                          case 4: removecar(1);
                                 
                          case 5: c=0;
                                  printf("Thanks for coming\n");
                                  break;
                          default :
                                  printf("you have entered out of choise\n");
                                  
                 }
        
              
              }
         return 0;  
      }
      addcars(int ad) 
             {
             if(carparking < 100)
             {
             printf("ferry is coming from mainland to take cars: \n");
             sleep(2);
             printf("Cars are added to parking lot \n");
             }
             else
             {
             printf("sorry no space for cars to park \n");
     	     }   
             return 0;
             }
       removecar(int rm)
		     {
                     while(carparking == 0)
                     {
                     printf("Total Parking lot is empty\n");
                     return 0;
                     }
                     printf(" Pleas enter number of cars leaving from parking lot : \n");
                     scanf("%d",&leavingcars);
                     if(leavingcars <=carparking)
		     {
                     carparking-=leavingcars;
                     parcapacity+=leavingcars;
                     printf("Ferry reaches to mainland from parking island \n");
                     }
                     else
                     {
                     printf("Invalid number of car enter \n");
                     } 
                     return 0;
                     }
