#include<stdio.h>
#include<string.h>

char* recursive(char *);
int main()
{
	char *str = "Shashank Arora";
	char *st;
	st = recursive(str);
	printf("%s\n",st);

	return 0;
}

char* recursive(char *s)
{
	int len = strlen(s);
	static char st[20];
	printf("len=%d\n",len);
	//if(len != 0)
	static int i = 0;
	if(len != 0)
	{
		//printf("--len = %d\n",len);
		len--;
		recursive(s+1);
		sleep(1);
		printf("s = %c\n",*s);
	//	st[i++] = *s;
	//	printf("st = %c\n",st[i]);
	}
	//printf("s = %s\n",s);

	return st;
}
