#include<stdio.h>

void fun(void);
void fun1(void);

int main()
{
	int x;
	fun();	
	fun1();
//	printf("x = %d\n",x);
	fun();
	
	return 0;
}

void fun(void)
{
	int x;
	printf("x = %d\n",x);
	
	x = 10;
	printf("...x... = %d\n",x);
	
}
void fun1(void)
{
	int x;
	printf("x = %d\n",x);
	
	x = 5;
	printf("...x... = %d\n",x);
}	
