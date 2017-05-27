#include<stdio.h>
#include<stdlib.h>


typedef struct node
{
	int data;
	struct node *next;
}NODE;

enum circular_linklist
{
	CREATE_CIRCULAR = 1,
	INSERT_NODE,
	PRINT,
	BEGINING_NODE,
	INSERT_AFTER_NODE
};

struct node * circular_linklist();
struct node * insert_node(struct node *);
struct node * begining(struct node *);
struct node * insert_after_node(struct node *);
void print(struct node *);

int main()
{
	int no;
	NODE *start = NULL;
	
	
	do{
	printf("CREATE_CIRCULAR LINKLIST       : Press 1\n");
	printf("INSERT NODE LINKLIST           : Press 2\n");
	printf("PRINT_CIRCULAR LINKLIST        : Press 3\n");
	printf("BEGINING NODE                  : Press 4\n");
	scanf("%d",&no);
	switch(no)
	{
		case CREATE_CIRCULAR:   start = circular_linklist(start);
					break;
		case INSERT_NODE:	start = insert_node(start);
					break;
		case PRINT:		print(start);
					break;
		case BEGINING_NODE:	start = begining(start);
					break;
		case INSERT_AFTER_NODE:	start = insert_after_node(start);	
	}
	}while(no != 100);
	
	return 0;
}

struct node * circular_linklist(NODE *start)
{
	if (start != NULL){
		printf("node already created\n");
		return start;		
	}

	int no;
	start = (struct node *)malloc(sizeof(struct node));
	printf("Enter data:\n");
	scanf("%d",&no);
	start->data = no;
	start->next = start;
	
	return start;
}

struct node * insert_node(struct node *start)
{
	int no;
	NODE *new_node = (struct node *)malloc(sizeof(NODE));
	
	printf("Enter no.\n");
	scanf("%d",&no);			
	new_node->data = no;	
	new_node->next = start->next;
	start->next = new_node;
	start = new_node;

	return start;	
}

struct node *begining(struct node *start)
{
	int no;
	NODE *begin = (struct node *)malloc(sizeof(NODE));
	
	printf("Enter no.\n");
	scanf("%d",&no);
	begin->data = no;			
	begin->next = start->next;
	start->next = begin;
					
	
	return start;
}

struct node * insert_after_node(struct node *temp)
{
	int node, no;

	printf("Insert after which node:\n");
	scanf("%d",&node);
	printf("Enter data:\n");
	scanf("%d",&no);

	NODE *new_node, *st;
	
	st = temp->next;

	do{

	if(st->data == node)
	{	
		new_node = (NODE *)malloc(sizeof(NODE));
		
		new_node->data = no;
		new_node->next = st->next;
		st->next = new_node;
	}

	st = st->next;

	}while(st != temp->next);
	
	
	return temp;
}

void print(NODE *node)
{
	NODE *new_node;
	
	if (node == NULL){
		printf("list empty\n");
		return;
	}
	new_node = node->next;
	
	do
	{
		printf("%d -> ",new_node->data);
		new_node = new_node->next;
	}
	while(new_node != node->next);				
	printf("\n");	
	
}	




