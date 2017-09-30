#include<stdio.h>

int main()
{
	int no = 15, a;

	// changing the nth bit to x

	no = no & ~(1 << 3) | (0 << 3);		
	printf("%d\n",no); 	

	// swap the bit
	
	int bit1 = (1 >> 0) & 1;
	int bit2 = (1 >> 8) & 1;

	int x = (bit1 ^ bit2);

	x = (x << 0) | (x << 8);
	
	int r = 1 ^ x;
	printf("%d\n",r); 	
		

	return 0;
}
