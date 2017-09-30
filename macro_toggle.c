#include<stdio.h>
#include<stdlib.h>

#define p(n,x) (n ^= (1<<x))  

int main()
{
	int a = 5;
	a = p(a,3);
	printf("%d\n",a);
	
	
	
	return 0;
}
