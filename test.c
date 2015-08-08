#include <stdio.h>
#include <malloc2.h>

int main()
{	
	int blocksize;
	int *ptr[1000];
	printf("\n Please enter the block size to be created : \n" );
	scanf("%d",&blocksize);
	malloc2(blocksize);
	free2(ptr[0]);
	
}