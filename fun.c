#include<stdio.h>

int fun(int ,int);
void func(char );
int main()
{

	int x = 5;	
	int y = 10;
	char c;
	c = fun(x,y);
//	printf("c = %c\n",c);
	//func();


	return 0;
}

int fun(int a, int b)
{
	int c;
	scanf(" %c",&c);
	int z = a + b;
	func(c);

	return c;
}

void func(char ch)
{
	printf("%c\n",ch);

}
