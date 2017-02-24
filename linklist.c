#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *next;
};


struct node * create_node(struct node *);
void insert_node(struct node *);
void print(struct node *);
void delete_node(struct node *);
struct node * reverse(struct node *);
struct node * begining(struct node *);
void middle(struct node *);
void insert_at_position(struct node *);
void delete_at_position(struct node *);

int main()
{
	char ch;
//	struct node *ret;	
	struct node *start = NULL;

	do{
	printf("          LINKLIST        \n");
	printf("  Create node  : press 'c'  \n");
	printf("  Insert node  : press 'i'  \n");
	printf("  Delete node  : press 'd'  \n");
	printf("  Display node : press 'p'  \n");
	scanf(" %c",&ch);
	switch(ch)
	{
		case 'c': start = create_node(start);
			  break;
		case 'i': insert_node(start);
			  break;
		case 'd': delete_node(start);
			  break;
		case 'p': print(start);
			  break;
		case 'r': start = reverse(start);
			  break;
		case 'b': start = begining(start);
			  break;
		case 'm': middle(start);
			  break;
		case 'g': insert_at_position(start);
			  break;
		case 'w': delete_at_position(start);
			  break;

	}
	}while(ch != 'e');
	
	
	return 0;
}

struct node *create_node(struct node *start)
{
	int no;
	
	if (start == NULL)
	{
		start = (struct node *)malloc(sizeof(struct node));
		printf("Enter data:\n");
		scanf("%d",&no);
		start->data = no;
		start->next = NULL;
	}

	printf("new_node = %p\n",start);
	return start;
}


void insert_node(struct node *node)
{
	struct node *new_node;
	int no;
//	new_node = start;
		
	if (node == NULL)
	{
		printf("First create a node\n");
		return;
	}
	while(node->next != NULL)
	{
		node = node->next;
	}
	new_node = (struct node *)malloc(sizeof(struct node));
	printf("Enter data:\n");
	scanf("%d",&no);
	new_node->data = no;
	node->next = new_node;
	new_node->next = NULL;
	
	
	printf("node = %p\n",node);
	printf("new_node = %p\n",new_node);
	printf("node->next = %p\n",node->next);
	printf("new_node->next = %p\n",new_node->next);
	
//	return start;
}	

void print(struct node *start)
{
	struct node *new_node = start;
	if (new_node == NULL)
	{	printf("No node is there\n");
		return;
	}
	
	while(new_node != NULL)
	{
		printf("%d -->", new_node->data);
		new_node = new_node->next;		
	}
	printf("NULL\n");
}

void delete_node(struct node *start)
{
	struct node *temp, *new_node = start;
	if (new_node == NULL)
	{
		printf("list empty\n");
		return;
	}
	while(new_node->next != NULL){
		temp = new_node;
		new_node = new_node->next;
	}	
	printf("%d\n",new_node->data);
	temp->next = new_node->next;	
	free(new_node);
}

struct node * begining(struct node *new_node)
{
	printf("new_node = %p\n",new_node);
	struct node *begin = (struct node *)malloc(sizeof(struct node));
	printf("Enter data\n");
	scanf("%d",&begin->data);
	printf("begin = %d\n",begin->data);
	printf("begin addr = %p\n",begin);
	printf("begin addr next = %p\n",begin->next);
	begin->next = new_node;
	printf("begin addr next = %p\n",begin->next);
	new_node = begin;
	printf("begin addr becomes start= %p\n",new_node);

	return new_node;		
}

struct node * reverse(struct node *new_node)
{
	struct node *prev,*current,*next = NULL;	
	prev = NULL;
	current = new_node;
	while(current != NULL){
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;		
	}	
	new_node = prev;
	
	return new_node;
}

void middle(struct node *new_node)
{
	
}

void insert_at_position(struct node *new_node)
{
	
}

void delete_at_position(struct node *new_node)
{
	
	
}
