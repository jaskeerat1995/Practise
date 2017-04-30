#include<stdio.h>
#include<stdlib.h>

#define R 10
#define C 20

void fun(int **p)
{
	static int q = 10;
	*p = &q;
}

char * func()
{

	return "awake";
}

int main()
{
/*
	char str[] = "geeksforgeeks";
	char *s1 = str, *s2 = str;     
	int i;
	
	for(i = 0; i < 7; i++)
	{
		printf(" %c ", *s1);
		++s1;     
	}
	
	for(i = 0; i < 6; i++)
	{
		printf(" %c ", *s2);
		++s2;     
	}
	printf("\n");	
*/

//################----------------##############//
	
//	int c=5;
//	printf("%d\n%d\n%d\n", c, c <<= 2, c >>= 2);

//################----------------##############//

/*	int r = 20;
	int *p = &r;
	fun(&p);
	printf("%d\n",*p);
*/

//################----------------##############//

/*	int a;
	char *x;
	x = (char*)&a;
	//a = 512;
	x[0] = 1;
	x[1] = 4;
	printf("a = %d\n",a);	
*/

//################----------------##############//

//	printf("%s\n",func() + printf("I SEE YOU\n"));

//################----------------##############//

//	int (*p) [R][C];
//	printf("%d\n",sizeof(*p));

//################----------------##############//
	
/*	int arr[] = {10, 20, 30, 40, 50, 60};
    	int *ptr1 = arr;
   	int *ptr2 = arr + 5;
    	printf ("ptr2 - ptr1 = %d\n", ptr2 - ptr1);
    	printf ("(char*)ptr2 - (char*) ptr1 = %d\n",  (char*)ptr2 - (char*)ptr1);
*/

/*	char arr[] = "geeksforgeeks";
    	char *ptr1 = arr;
    	char *ptr2 = ptr1 + 3;
    	printf ("ptr2 - ptr1 = %d\n", ptr2 - ptr1);
    	printf ("(int*)ptr2 - (int*) ptr1 = %d\n",  (int*)ptr2 - (int*)ptr1);
*/	
/*	char arr[] = "geeks\0 for geeks";
	char *str = "geeks\0 for geeks";
	printf ("arr = %s, sizeof(arr) = %d \n", arr, sizeof(arr));
	printf ("str = %s, sizeof(str) = %d\n", str, sizeof(str));	
*/

//################----------------##############//

/*	struct str
	{
		int i: 1;
		int j: 2;
		int k: 3;
		int l: 4;
	};

	struct str s;

	s.i = 1;
	s.j = 2;
	s.k = 5;
	s.l = 10;

	printf(" i: %d \n j: %d \n k: %d \n l: %d \n", s.i, s.j, s.k, s.l);
	
*/

//################----------------##############//

	printf("GEEKS size = %d \n\n", sizeof("GEEKS"));
    	printf("GEEKS length = %d \n", strlen("GEEKS"));
//sizeof() function returns the size of the string including null character while strlen() function returns length of the string excluding null character//

	
	
	return 0;
}


