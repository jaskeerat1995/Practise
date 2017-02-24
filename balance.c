#include<stdio.h>
#include<stdlib.h>
	
struct node
{	
	char ch;
	struct node *next;
};	
		
void  push(struct node **, char );
int pop(struct node **);
void print(struct node **);
void Isparentheses_balanced(struct node **);
int Ismatching_pair(char , char);	
	
int main()
{
	char c;
	char data;
	struct node *stack = NULL;
	
	do{
		printf("Insert Parenthese    :    Press 'i' \n");
		printf("  POP  Parenthese    :    Press 'd' \n");
		printf("Print  Parenthese    :    Press 'p' \n");
		printf("      EXIT           :    Press 'e' \n");
		scanf(" %c",&c);
		switch(c)
		{
//			case 'i':	stack = push(stack,&data);
//					break;
			case 'd':	data = pop(&stack);
					break;
			case 'b':	Isparentheses_balanced(&stack);
					break;
			case 'p':	print(&stack);
					break;
		}
	 
	}while(c != 'e');
	
	return 0;
}	
	

	
void push(struct node **top, char data)
{
	struct node *new_node;
//	char data;
	
	new_node = (struct node *)malloc(sizeof(struct node));	
//	printf("top must be= %p\n",*top);
//	printf("Enter parentheses:\n");
//	scanf(" %c",&data);
//	printf("push = %c\n",data);
	new_node->ch = data;
	new_node->next = *top;
	*top = new_node;	
//	printf("top = %p\n",*top);
 //       printf("top->data = %c\n",(*top)->ch);
   //     printf("top->next = %p\n",(*top)->next);	

}	
	
int pop(struct node **top)
{	
	struct node *new_node;
	char ret;
	new_node = *top;
	ret = new_node->ch;
	printf("ret = %c\n",ret);
	*top = (*top)->next;
	free(new_node);
	
	return ret;
}	
	
void print(struct node **stack)
{	
	struct node *new_node;
	new_node = *stack;
	while(new_node != NULL)
	{
		printf("%c -->",new_node->ch);
		new_node = new_node->next;
	}
	printf("NULL\n");
}	

void Isparentheses_balanced(struct node **char1)
{
	char ch, ch1;
	struct node * new;
	printf("Enter parentheses:\n");
	scanf(" %c",&ch);
//	printf("char1 = %p\n",*char1);
//	printf("char1 = %p\n",**char1);
//	printf("parentheses ch = %c\n",ch);
	if (ch == '{' || ch == '[' || ch == '(')
	{
		push(char1,ch);
	}
	
	if (ch == '}' || ch == ']' || ch == ')')
	{
		Ismatching_pair(pop(char1),ch);
	}
			
	
}	
	
int Ismatching_pair(char del, char ch)	
{
//	printf("del = %c\n",del);	
//	printf("ch = %c\n",ch);	
	if (del == '{' && ch == '}'){
		printf("matched\n");
		return 1;
	}	
	else if (del == '(' && ch == ')'){
		printf("matched\n");
		return 1;	
	}
	else if (del == '[' && ch == ']'){
		printf("matched\n");
		return 1;	
	}
	else{
		printf("Doesn't match\n");
		return 0;
	}
	
	return 0;
}
		
