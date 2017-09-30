#include<stdio.h>
#include<string.h>
	
int Atoi(const char *);
	
int main()
{	
	const char *str = "sgadsada";
	int val;

	val = Atoi(str);
	printf("val = %d\n",val);
	
	
	return 0;
}	
	
int Atoi(const char *s)	
{		
	int i, len;
	int ret = 0;
	
	len = strlen(s);
	
	for(i = 0; i < len; i++)
	{	
		if (*(s + i) < '0' || *(s + i) > '9')
			return ret;

		ret = ret * 10 + *(s + i) - '0';
		printf("ret = %d\n",ret);
	}	
	
	return ret;
}	
		
	
