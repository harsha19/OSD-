#include <stdlib.h>
#include <stdio.h>

// Program is designed to create one block of variant in size

struct mytuplerecorder 
{

		int *addr;
		size_t len;

};

int main()
{
	int *ptr[1000];
	struct mytuplerecorder tr;
	int blocksize;
	printf("Please enter your choice of function:");
	printf("\n 1: For malloc2 \n");
	printf("\n 2: For free2 \n");

	// MALLOC2
	{
		printf("\n Please enter the block size to be created : \n" );
		scanf("%d",&blocksize);

		ptr[0]=malloc(blocksize);
		//if (tr.addr[1] == NULL)
			//errExit("malloc");
		tr.addr=ptr[0];
		tr.len=blocksize;
		printf("Address is : %10p \n",tr.addr );
		printf("Size is : %zu\n",tr.len );


	}
	//FREE2
	{

		printf("Break point is at : %10d \n",sbrk(0) );
		printf("Now entering Free2 function\n");
		tr.addr=0;
		// use a counter to check it (the 2nd part if 2nd question)
		free(ptr[0]);
		printf("Address is : %10p\n",tr.addr );
		printf("After Freeing the break point is at :%10d \n",sbrk(0) );
	}

	
}