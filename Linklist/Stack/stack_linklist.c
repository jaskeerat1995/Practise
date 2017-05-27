#include<stdio.h>
#include<stdlib.h>
	
struct node
{	
	char ch;
	struct node *next;
};	
		
struct node * push(struct node *);
struct node * pop(struct node *);
void print(struct node *);
	
int main()
{
	char c;
	struct node *stack = NULL;
	
	do{
		printf("Insert Parenthese    :    Press 'i' \n");
		printf("  POP  Parenthese    :    Press 'd' \n");
		printf("Print  Parenthese    :    Press 'p' \n");
		printf("      EXIT           :    Press 'e' \n");
		scanf(" %c",&c);
		switch(c)
		{
			case 'i':	stack = push(stack);
					break;
			case 'd':	stack = pop(stack);
					break;
			case 'p':	print(stack);
					break;
		}
	 
	}while(c != 'e');
	
	return 0;
}	
	

	
struct node * push(struct node *top)
{
	struct node *new_node;
	char data;
	
	new_node = (struct node *)malloc(sizeof(struct node));	
	printf("Enter parentheses:\n");
	scanf(" %c",&data);
	new_node->ch = data;
	new_node->next = top;
	top = new_node;	
	printf("top = %p\n",top);
	printf("top->data = %c\n",top->ch);
	printf("top->next = %p\n",top->next);
	
	
	return top;
}	
	
struct node * pop(struct node *top)
{	
	struct node *new_node;
	new_node = top;
	printf("%p\n",new_node);
	printf("%c\n",new_node->ch);
	printf("%p\n",new_node->next);
	top = top->next;
	free(new_node);
	return top;
}	
	
void print(struct node *stack)
{	
	struct node *new_node;
	new_node = stack;
	printf("stack= %p\n",stack);
	printf("stack->data = %c\n",stack->ch);
	printf("stack->next = %p\n",stack->next);
	while(new_node != NULL)
	{
		printf("%c -->",new_node->ch);
		new_node = new_node->next;
	}
	printf("NULL\n");
}	
	
