#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>

int ferry,parking_lot,waitingcars;
int park_capacity=150,cars_leaving;

int add_cars(int add) 
    {
      if(parking_lot < 150)
        {
          printf("ferry is coming from mainland to carry cars to island: \n");
          printf("Cars are added to parking lot \n");
        }
      else
        {
         printf("Filled  completely\n");
        }   
         return 0;
    }


int remove_cars(int remove)
    {
      while(parking_lot == 0)
        {
         printf("Parking lot is completely empty\n");
         return 0;
        }
        printf("enter number of cars which are leaving from parking lot : \n");
        scanf("%d",&cars_leaving);
        if(cars_leaving <=parking_lot)
		     {
           parking_lot=parking_lot-cars_leaving;
           park_capacity=park_capacity+cars_leaving;
           printf("Ferry reached to mainland from island \n");
         }
        else
        {
            printf("number of cars entered is invalid \n");
        } 
        return 0;
    }



 int main()
    {
     int x,opt=1;
     if(opt)
	  {
        printf("Car Parking options:-\n 1. No.of cars already in the parking_lot \n 2. No.of Arrived cars \n 3. Number of cars leaving \n 4. capacity to park cars in the parking_lot \n") ;
        printf("5. Exit \n");
        printf("enter your choice \n");
        scanf("%d",&x);
        switch(x)
		{
         case 1:
		            printf(" Number of cars in parking lot are :  %d \n",parking_lot);
         case 2:
                printf("Enter the no of cars waiting to get parked: \n");
                scanf("%d",&waitingcars);
                ferry=ferry+waitingcars;
                 waitingcars=0; 
                if(ferry<=park_capacity)
                  {
                      add_cars(1);
                      parking_lot=parking_lot+ferry;
                      park_capacity=park_capacity-ferry;
                      ferry=0;
                  }
                else
		              {
                      if(ferry>=park_capacity && park_capacity!=0)
			                  {
                          printf("Space available in parking lot is %d:  \n",park_capacity);
                          printf("ferry should carry less than the space available\n");
                          ferry=0;
                        }
                      else
		                    {
                          printf("There is no more capacity in parking lot \n");
                        }
                   }
		      case 3:
                    remove_cars(1);
          case 4:
		                printf("available capacity to park cars in lot: %d \n",park_capacity); 
         case 5: 
		              opt=1;
                  printf("Thankyou..see u again\n");
                   break;
         default :
                  printf("wrong choice:not in options\n");
          }
    }
return 0;  

}
           
 