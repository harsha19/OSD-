#include "malloc2.h"
#include <stdio.h>

/* Program is Designed considering only one block is created with size of our choice */

struct mytuplerecorder 
{
	int *addr;
	size_t len;

};

struct mytuplerecorder tr;

void *malloc2(size_t blocksize)

{
	ptr[0]=malloc(blocksize);
	tr.addr=ptr[0];
	tr.len=blocksize;
	printf("Address is : %10p \n",tr.addr );
	printf("Size is : %zu\n",tr.len );
}

void free2(void *ptr)
{	
	int count=0;
	printf("Break point is at : %10d \n",sbrk(0) );
	printf("Now entering Free2 function\n");
	
		// use a counter to check it (the 2nd part if 2nd question)
	if (count =1) then
		exit 
	else 
	tr.addr=0;
	free(ptr[0]);
	count=1;
	printf("Address is : %10p\n",tr.addr );
	printf("After Freeing the break point is at :%10d \n",sbrk(0) );
}

