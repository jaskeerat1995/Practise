#include<stdio.h>

struct var
{
	char *c;
};

struct arr
{
	int a;
	char c[20];
};


int main()
{

/*	struct var s;
	s.c = "hello";
	printf("%s\n",s.c);

*/

////##############----------------#############/////

	static int a = 2;
	
	if (a == 2){
		a = ~a + 2 << 3;
		printf("a = %d\n",a);
	}


////##############----------------#############/////
	
//	struct arr s;
//	printf("%d\n",sizeof(struct arr));				
	
////##############----------------#############/////
	
/*	int a = 3;
	float f = 3.0;

	if (a == f)
	{
		printf("are equal\n");
	}
	else
		printf("are not equal\n");
*/

////##############----------------#############/////
		
/*	float a = 0.7;
	
	if(a == 0.7)
	{
		printf("are equal\n");
	}
	else
		printf("are not equal\n");
*/

////##############----------------#############/////
	

/*	float f = 3.5;

	if (f == 3.5)
	{
		printf("are equal\n");
	}
	else
		printf("are not equal\n");

*/
	
////##############----------------#############/////

/*	const int a = 5;	
	const int *p = &a;
	*p = 10;
	printf("%d\n",a);
*/

////##############----------------#############/////
	
	
	
	
	
	return 0;

}
