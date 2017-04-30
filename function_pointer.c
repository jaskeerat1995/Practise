#include<stdio.h>

struct node
{
	void *data;
};

struct node *start = NULL;


int a = 5;
int *p = &a;

void datanode(void (*fptr) (void *))
{
	(*fptr)(p);	

}

void printInt(void *n)
{
	printf("%d\n",*(int *)n);
}

int main()
{
		
	//printf("%d\n",(*fptr) datanode());
	//printf("%p\n",fptr);	
	datanode(printInt);
	
	return 0;
}

