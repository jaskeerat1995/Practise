#include<stdio.h>
#include<stdlib.h>

int substring(char *);

int main()
{	
	char *string = (char *)malloc(sizeof(char) * 100);
	scanf("%s",string);
	
	substring(string);
	

	return 0;
}

int substring(char *str)
{
	int i = 0, k = 0, count = 0, run = 0;
	
	while(*(str + i) != '\0')
	{
		while(*(str + i) == *(str + k + 1))
		{
			count++;
			k++;
		}
		
		if(count >= run)
		{
			run = count;
		}
		count = 0;
		i = k + 1;
	}
	printf("run = %d\n",run);
	
	return 0;
}
