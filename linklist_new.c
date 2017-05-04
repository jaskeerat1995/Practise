#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *next;
};

enum linklist{
        CREATE_NODE = 1,
        INSERT_NODE,
        PRINT,
        DELETE_NODE,
        REVERSE,
        BEGINING,
        MIDDLE,
        SORT,
        INSERT_AT_POSITION,
        DELETE_AT_POSITION,
        REMOVE_DUPLICITY,
        LOOP_DETECT,
	DELETE_FIRST
};


struct node * create_node(struct node *);
void insert_node(struct node *);
void print(struct node *);
void delete_node(struct node **);
struct node * reverse(struct node *);
struct node * begining(struct node *);
void middle(struct node *);
struct node * sort(struct node *);
struct node * insert_at_position(struct node *);
struct node * delete_at_position(struct node *);
struct node * remove_duplicity(struct node *);
void loop_detect(struct node *);
struct node * delete_first(struct node *);

int main()
{
	int no;
//	struct node *ret;	
	struct node *start = NULL;

	do{
	printf("          LINKLIST        \n");
	printf("  Create node  : press 1  \n");
	printf("  Insert node  : press 2  \n");
	printf("  Display node : press 3  \n");
	printf("  Delete node  : press 4  \n");
	printf("     Reverse   : press 5  \n");
	printf("    Begining   : press 6  \n");
	printf("  Find middle  : press 7  \n");
	printf("  Insert at position  : press 9  \n");
	printf("  Delete at position  : press 10  \n");
	printf("  Remove duplicate node  : press 'j'  \n");
	printf("  loop detect : press 'l'  \n");
	scanf("%d",&no);
	switch(no)
	{
		case CREATE_NODE: 	start = create_node(start);
				  	break;
		case INSERT_NODE: 	insert_node(start);
				  	break;
		case DELETE_NODE: 	delete_node(&start);
				  	break;
		case PRINT:       	print(start);
					break;
		case REVERSE: 		start = reverse(start);
			      		break;
		case BEGINING: 		start = begining(start);
			  		break;
		case MIDDLE: 		middle(start);
			  		break;
		case SORT: 		start = sort(start);
			  		break;
		case INSERT_AT_POSITION:start = insert_at_position(start);
			  		break;
		case DELETE_AT_POSITION:start = delete_at_position(start);
			  		break;
		case REMOVE_DUPLICITY: 	start = remove_duplicity(start);
			  		break;
		case LOOP_DETECT: 	loop_detect(start);
			  		break;
		case DELETE_FIRST:	delete_first(start);
					break;

	}
	}while(no != 100);
	printf("Deleting nodes....\n");
	while(start != NULL)
	{
		if (start == NULL)
			return;
		delete_node(&start);
	}
	printf("..done!!\n");	
	
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

void delete_node(struct node **start)
{
	struct node *new_node = *start, *temp;
	//temp = new_node;
	
	if (new_node == NULL)
	{
		printf("list empty\n");
		return;
	}
	
	if (new_node->next == NULL)
	{
		//temp = new_node;
		*start = new_node->next;
		free(new_node);
		return;
	}

	while(new_node->next != NULL){
		temp = new_node;
		new_node = new_node->next;
	}	
	printf("new_node->next = %p\n",new_node->next);
	printf("new_node->data = %d\n",new_node->data);
	printf("temp->data = %d\n",temp->data);
	

	temp->next = new_node->next;	
	free(new_node);
	printf("temp->next = %p\n",temp->next);
}

struct node * delete_first(struct node *new_node)
{
	

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

struct node * sort(struct node *new_node)
{
	struct node *node;
	int temp;
	struct node *start;
	start = new_node;
	
	while(new_node->next != NULL)
	{
		node = new_node;
		while(node->next != NULL)
		{
			if(node->data > node->next->data)
			{
				temp = node->data;
				node->data = node->next->data;
				node->next->data = temp;
			}	
		node = node->next;
		}
	new_node = new_node->next;
	}
	
	return start;
}
	
void middle(struct node *new_node)
{	
	int count = 1;
	struct node *slow_ptr, *fast_ptr;
	slow_ptr = fast_ptr = new_node;
	
	while(slow_ptr != NULL && fast_ptr != NULL && fast_ptr->next != NULL)
	{
		slow_ptr = slow_ptr->next;
		fast_ptr = fast_ptr->next->next;
		count++;
	}
	printf("middle position at %d\n",count);
	printf("middle element :  %d\n", slow_ptr->data);
}	
	
struct node * insert_at_position(struct node *current)
{	
	int pos, i, dat;
	struct node *ret;
	struct node *prev, *new_node;
	new_node = (struct node *)malloc(sizeof(struct node));
	printf("Enter position: \n");
	scanf("%d",&pos);
	//prev = current;
	
	if (pos == 1)
	{
		ret = begining(current);
		return ret;
	}
	if (pos > 1)
	{
		for(i = 1; i < pos; i++){
			prev = current;
		/*	printf("prev = %p\n",prev);
			printf("prev->next = %p\n",prev->next);
			printf("current = %p\n",current);
			printf("current->next = %p\n",current->next);
		*/	current = current->next;
		//	printf("current = %p\n",current);
		//	printf("current = current->next = %p\n",current->next);
		}
		printf("Enter new node:\n");
		scanf("%d",&dat);
		new_node->data = dat;
		new_node->next = current; 
		prev->next = new_node;	
	}
		
	return;
}	
	
struct node * delete_at_position(struct node *new_node)
{	
	int no, count = 1;
	struct node *prev, *temp;
	temp = new_node;
	printf("Enter the position: \n");
	scanf("%d",&no);
	while(count != no)
	{
		if(temp->next != NULL)
		{
			prev = temp;
			temp = temp->next;	
		}
		count++;
	}	
	printf("prev->data = %d\n",prev->data);
	printf("temp->data = %d\n",temp->data);
	prev->next = temp->next;
	free(temp);
	
	return new_node;
}	
	
struct node * remove_duplicity(struct node *new_node)
{	
	struct node *rmv, *prev, *temp;
	prev = temp = new_node ;
		
	while(prev->next != NULL)
	{	
		temp = prev;
		while(temp->next != NULL)
		{
			printf("prev->data = %d\n",prev->data);
			if(prev->data == temp->next->data)
			{
				rmv = temp->next;
				prev->next = temp->next->next;
				free(rmv);
				printf("temp->data = %d\n",temp->next->data);
			}
			else
			{
				temp = temp->next;
			}
		}
		prev = prev->next;
		if ((prev->next == NULL) && (temp->next== NULL))
			{
				printf("finish\n");
				//return new_node;
				break;
			}
	}	
		
	return new_node;
}	
	
void loop_detect(struct node *new_node)
{	
	struct node *slow, *fast;
	slow = fast = new_node;
	
	//while()
	
	
}	
	
