#include<stdio.h>
#include<stdlib.h>
	
struct node
{	
	char ch;
	struct node *next;
};	
	
struct queue
{
	struct node *stack1;
	struct node *stack2;
};
	
struct queue * enqueue(struct queue *);
void dequeue(struct queue *);
struct node * push(struct node *);
char pop(struct node **);
void push2(struct node **, char );
void print(struct node *);
	
int main()
{
	char c;
	struct queue *q = (struct queue*)malloc(sizeof(struct queue));
	q->stack1 = NULL;
	q->stack2 = NULL;
	
	do{
		printf("Insert Parenthese    :    Press 'i' \n");
		printf("  POP  Parenthese    :    Press 'd' \n");
		printf("Print  Parenthese    :    Press 'p' \n");
		printf("      EXIT           :    Press 'e' \n");
		scanf(" %c",&c);
		switch(c)
		{
			case 'i':	q->stack1 = enqueue(q);
					break;
			case 'd':	dequeue(q);
					break;
			case 'p':	print(q->stack1);
					break;
		}
	 
	}while(c != 'e');
	
	return 0;
}	
	
struct queue * enqueue(struct queue *e)
{
	return push(e->stack1);
}
	
void dequeue(struct queue *d)
{
	char c;
	if (d->stack1 == NULL && d->stack2 == NULL){
		printf("queue is empty\n");
		return;
	}
	if(d->stack2 == NULL)
	{
		while(d->stack1 != NULL){
			c = pop(&d->stack1);
			push2(&d->stack2,c);
		}
	}

	print(d->stack2);
	pop(&d->stack2);
	print(d->stack2);
	
}

void push2(struct node **top2, char c)
{
	struct node *new_node;
	new_node = (struct node *)malloc(sizeof(struct node));	
	new_node->ch = c;
	new_node->next = *top2;
	*top2 = new_node;	

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
	
char pop(struct node **top)
{	
	struct node *new_node;
	char del;
	new_node = *top;
	if (*top == NULL){
		printf("stack empty!\n");
		return;
	}
	printf("top_node = %p\n",new_node);
	del = new_node->ch;
	printf("del = %c\n",del);
	printf("%p\n",new_node->next);
	*top = new_node->next;
	free(new_node);

	return del;
}	
	
void print(struct node *stack)
{	
	struct node *new_node;
	new_node = stack;
	printf("stack= %p\n",stack);
	printf("stack->data = %c\n",stack->ch);
	printf("stack->next = %p\n",stack->next);
	if (new_node == NULL){
		printf("Stack empty!! Nothing to print\n");
		return;
	}
	while(new_node != NULL)
	{
		printf("%c -->",new_node->ch);
		new_node = new_node->next;
	}
	printf("NULL\n");
}	
	
