#include<stdio.h>

/*struct{
	int x;
}var = {5}, *p = &var;
*/



int x = 5;

int* f() 
{
	return &x;
}

int main()
{
	//float f = 4.23;
	//printf("%d\n",f);

	/*char s[] = "fine";
	 *s = 'N';

	 printf("%s\n",s);	
	 */

	/*	char *s = "Hello, "
		"World!";

		printf("%s\n",s);
	 */

	/*	int i;

		char s[] = "hello";

		for(i = 0; s[i]; ++i)
		printf("%d\n",i);	
		i = 0;
		while(s[i++])		
		printf("%d\n",i);

	 */

	//	printf("%d %d %d \n",var.x, p->x, (*p).x);

/*
		*f() = 10;

		printf("%d\n", x);
*/	 

	/*	char s[] = "hello", t[] = "hello";

		if(s == t)
		printf("equal");
	 */

	/*	char c = 'A' + 255;
		printf("%c\n",c);
	 */

	/*	int *p = 15;
		printf("%d\n",*p);
	 */

	/*	register int a = 10;

		int *p = &a;
		a++;
		printf("%d\n",*p);
	 */

	/*	float t = 2;

		switch(t)
		{
		case 2: printf("Hi");
		default: printf("hello");
		}
	 */

	/*	int a[3] = {2, ,1};
		printf("%d\n",a[a[0]]);	
	 */

	/*	int a = 3;

		a += 2;
		a =+ 2;
		printf("%d\n",a);	
	 */

/*	char *s = "Hello";
	while(*s != NULL)
		printf( "%c",*s++);	
*/
	
/*	float f = 3.6;
	int y = int(int f + 0.5);
	
	printf("result = %d\n",y);	
*/

/*	float a = 3.14f;	
	printf("%f\n",a);
*/


/*	const int x=5;
	int *ptrx;
	
	ptrx = &x;
	*ptrx =10;
   	printf("%d\n",x);	
*/

	puts(__DATE__);	
	
	return 0;
}
