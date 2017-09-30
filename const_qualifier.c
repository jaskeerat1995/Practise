#include<stdio.h>
	
//extern int a;
	
int main()
{	
/*	
	const int a = 10;
	a = 20;
	printf("a = %d\n",a);
*/	
	
/*	const int a = 10;
	int b = 20;
	printf("address of a = %x\n",a);
	printf("address of b = %x\n",b);
	
	 int *ptr = &a;
	
	//ptr = &b;
	
	printf("adrress of ptr = %x\n",*ptr);	
	
	*ptr = 100;
	printf("value in ptr = %d\n",*ptr);	
*/	
	
/*	const int a = 10;
	const int b = 20;
	printf("address of a = %x\n",a);
	printf("address of b = %x\n",b);
	
	const int *ptr = &a;
	
	ptr = &b;
	
	printf("adrress of ptr = %x\n",*ptr);	
	
	*ptr = 100;
	printf("value in ptr = %d\n",*ptr);	
*/	
	
	int const a = 10;
	int const b = 20;
	printf("address of a = %x\n",a);
	printf("address of b = %x\n",b);
	
	int *const ptr = &a;
	
	ptr = &b;
	
	printf("adrress of ptr = %x\n",*ptr);	
	
	*ptr = 100;
	printf("value in ptr = %d\n",*ptr);	

	
		
	return 0;
}
