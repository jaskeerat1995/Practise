#include<stdio.h>
#include<stdlib.h>


int main()
{
	long int no = 9041914103, new = 0;	
	printf("no = %ld\n",no);
	int count = 0, div;
	
	while(count != 10)
	{
		new = (new * 10) + (no % 10);
		printf("new = %ld\n",new);
		no = no / 10;
		printf("no = %ld\n",no);
		count++;
	}
	
	return 0;
}
