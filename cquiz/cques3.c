#include<stdio.h>

long fu(int);
char vect[] = {1,2,3,4,5};

int main()
{

/*	int a = 5;
	static int b = a;
	printf("%d  %d\n",a,b);
*/

////##############--------------------##################////

/*	int num, a = 10;
	num = a--- -a--;
	printf("%d %d\n",num,a);		
*/
	
////##############--------------------##################////

/*	int a[] = {5,10,15};
	int i = 0, num;
	num = a[++i] + ++i + (++i);
	printf("%d %d\n",num,i);
*/

////##############--------------------##################////

/*	int a, i = 4;
	a =- -i+- -i+- -5;
	printf("%d  %d\n",a,i);
*/

////##############--------------------##################////

		
/*	int a = 5, num;
	num =---a;
	printf("%d \n",num);
*/	
	
////##############--------------------##################////
	
/*	float **(*ptr)[4] = (float **(*)[4])0;
	ptr += 5;
	printf("%d %d\n",ptr,sizeof(ptr));
	float *p;
	printf("%d\n",sizeof(p));
*/
	
////##############--------------------##################////
	
	int i = 1;
	i = fu(++i) + ++vect[++i] + ++i + fu(i++);
	printf("%d\n",i); 		
	
	
	
	
	
	return 0;
}

long fu(int x)
{
	return x * 3;
}

