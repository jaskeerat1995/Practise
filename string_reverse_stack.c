#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct stacknode
{
	int top;
	int capacity;
	int *arr;
};

//char *pop = (char*) malloc(sizeof(char) * 26);
struct stacknode* create_stack();
void print(struct stacknode*);
void push(struct stacknode*);
//int pop(struct stacknode*);
int isstack_full(struct stacknode*);
int isstack_empty(struct stacknode*);

int main()
{
	char pop[26];
	char n;
	struct stacknode* stack;
	stack->top = -1;
	char *str = "My name is Shashank Arora";
	int len = strlen(str);
	printf("Strlen=%d\n",len);
	int count = 0;
	stack->capacity = len;	
	
	while(stack->top != stack->capacity-1)
	{
		stack->arr[++stack->top] = *(str + count);
		printf("stack->arr[%d] = %c\n",stack->top,*(stack->arr + stack->top));
		count++;
	}
	printf("stack->top = %d\n",stack->top);
	count = 0;
	while(stack->top != -1)
	{
		*(pop + count) = stack->arr[stack->top--];
	//	printf("%c",*(pop+count));
		count++;
	}	
	count = 0;
	for(count = 0; count < len; count++)
	{
		printf("%c",*(pop+count));
	}	

	return 0;
}
/*
int isstack_full(struct stacknode* stack)
{
	return (stack->top == (stack->capacity - 1));
}

int isstack_empty(struct stacknode* stack)
{
	return (stack->top == -1);
}

struct stacknode* create_stack()
{
	int c;
	struct stacknode* stack;
	stack = (struct stacknode*)malloc(sizeof(struct stacknode));
	printf("Enter capacity of the stack: \n");
	scanf("%d",&c);
	stack->capacity = c;
	
	return stack;
}


void push(struct stacknode* stack)
{
	int data;
	if (isstack_full(stack))
	{
	    printf("Stack full\n");
	    return;
	}
	printf("Enter data:\n");
	scanf("%d",&data);
	stack->arr[++stack->top] = (int)data;
	
}

void print(struct stacknode* stack)
{
	printf("stack-top: %d\n",stack->top);
	int count;
	count = stack->top;
	while(count != -1)
	{
		printf("%d\n",*(stack->arr + count--));
	}
}
*/
