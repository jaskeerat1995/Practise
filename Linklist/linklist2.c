#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *next;
};

//struct node *start = NULL;

void insert_node(struct node **);
//struct node* create_node(struct node *);
void print(struct node **);
void delete_node();

int main()
{
	char ch;
	struct node *ret;	
	struct node **start = NULL;

	do{
	printf("          LINKLIST        \n");
	printf("  Insert node  : press 'i'  \n");
	printf("  Delete node  : press 'd'  \n");
	printf("  Display node : press 'p'  \n");
	scanf(" %c",&ch);
	switch(ch)
	{
		case 'i': insert_node(&start);
			  break;
		case 'd': delete_node();
			  break;
		case 'p': print(&start);

	}
	}while(ch != 'e');
	
	
	return 0;
}

/*struct node *create_node(struct node *start)
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

	return start;
}
*/

void insert_node(struct node **start)
{
	struct node *new_node;
	int no;
	new_node = *start;
	printf("new_node = %p\n",new_node);
	if (new_node == NULL)
	{
		new_node = (struct node *)malloc(sizeof(struct node));
		printf("Enter data:\n");
		scanf("%d",&no);
		new_node->data = no;
	printf("new_node->data = %d\n",new_node->data);
		new_node->next = NULL;
	printf("new_node->next = %p\n",new_node->next);
	*start = new_node;
	}
	else
	{
	while(new_node->next != NULL)
	{
		new_node = new_node->next;
	}
		new_node->next = (struct node *)malloc(sizeof(struct node));
		printf("Enter data:\n");
		scanf("%d",&no);
		new_node->next->data = no;
		new_node->next->next = NULL;
	printf("new_node->next->data = %d\n",new_node->next->data);
	printf("new_node->next->next = %p\n",new_node->next);
	}
//	return start;
}	

void print(struct node **start)
{
	struct node *new_node = *start;
	while(new_node != NULL)
	{
		printf("%d -->",new_node->data);
		new_node = new_node->next;
	}
	printf("NULL\n");
}

void delete_node()
{

}
