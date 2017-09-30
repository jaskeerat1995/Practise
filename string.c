#include<stdio.h>
#include<string.h>
	
int main()
{	
	char *str = "Shashank Arora";
		
	int len = strlen(str);
	printf("%d\n",len);	

	int size = sizeof(str);
	printf("%d\n",size);	
	
	return 0;
}	
	
	
	
