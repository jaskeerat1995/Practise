#include<stdio.h>
#include<stdlib.h>
	
typedef struct node
{
	int data;
	struct node *next;
}NODE;
	
struct queue
{	
	struct node *rear;
	struct node *front;
};

enum queue_linklist
{
	CREATE = 1,
	ENQUEUE,
	DEQUEUE,
	PRINT
};	
	
struct queue * create_queue(struct queue *);
struct queue * enqueue(struct queue *);
struct queue * dequeue(struct queue *);
void print(struct queue *);

int main()
{
	int no;
	struct queue *q;
	
	do{
		printf("Implement Queue Using Linklist\n");
		printf("Create Enqueue   :   Press 1\n");
		printf("   Enqueue       :   Press 2\n");
		printf("   Dequeue       :   Press 3\n");
		printf("   Print         :   Press 4\n");
		scanf("%d",&no);
		
		switch(no)
		{
			case CREATE: 	q = create_queue(q);
					break;
			case ENQUEUE:	q = enqueue(q);
					break;
			case DEQUEUE:	q = dequeue(q);
					break;
			case PRINT:	print(q);
					break;
	
		}
	}while(no != 100);
	
	
	
	return 0;
}	
	
struct queue * create_queue(struct queue *q)
{	
	q = (struct queue *)malloc(sizeof(struct queue));
	q->rear = q->front = NULL;
	
	return q;
}	
	
struct queue * enqueue(struct queue *q)
{	
	int no;
	
	if (q->rear == NULL)
	{
		NODE *new_node = (struct node *)malloc(sizeof(NODE));
		printf("Enter data: \n");
		scanf("%d",&no);
		new_node->data = no;
		new_node->next = NULL;		
		q->rear = q->front = new_node; 
		return q;
	}	
	NODE *new_node = (struct node *)malloc(sizeof(NODE));
	printf("Enter data.....: \n");
	scanf("%d",&no);
	new_node->data = no;
	q->rear->next = new_node;
	q->rear = new_node;
	
	return q;	
}	
	
struct queue * dequeue(struct queue *q)
{	
	if(q->front == NULL)
	{
		printf("Queue is empty\n");
		return NULL;
	}

	struct queue *temp;
	temp = q->front;
	q->front = q->front->next;
	return temp;
	
}	
	
void print(struct queue *que)
{
	struct node *q;
	q = que->front;
	while(q != NULL)
	{
		printf("%d -> ",q->data);
		q = q->next;
	}
	printf("NULL\n");
}	

	
	
