#include<stdio.h>

int main()
{
	char *p = "shashank";
	
	*(p + 3) = 'd';
	printf("%s\n",p);	
	
}
