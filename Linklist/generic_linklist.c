#include<stdio.h>
#include<stdlib.h>


typedef struct node{
	void *data;
	struct node *next;
}mynode;	

	
/*void printInt(void *);
void printFloat(void *);
void printChar(void *);
void print(struct node *, void *);
void insert(struct node **, void *, int );
*/


void insert(struct node **start, void *data, int data_size)
{
	int i;
	mynode *new_node = (struct node *)malloc(sizeof(mynode));
//	if (*start == NULL)
//	{
		new_node->data = malloc(data_size);
		new_node->next = *start;
		
		for(i = 0; i < data_size; i++){
			*(char *)(new_node->data + i) = *(char *)(data + i);
	//		printf("int = %d\n",*(int *)(new_node->data + i));
			}
		
		*start = new_node;
//	}
		

}	

void print(struct node *node, void (*fptr) (void *))
{
	while(node != NULL){
		(*fptr)(node->data);
		node = node->next;
	}
}
	
void printInt(void *data)
{
	printf("%u\n",*(int *)data);
}	

void printChar(void *data)
{
	printf("%c\n",*(char *)data);
}
	
void printFloat(void *data)
{
	printf("%f\n",*(float *)data);
}

int main()
{	
	mynode *start = NULL;
	int no, int_size, float_size, char_size, i;
	
	int arr[] = {1,2,512,256,65536};
	float arr2[] = {1.23, 21.2, 32.45, 23.44};
	int_size = sizeof(int);
	float_size = sizeof(float);
	char_size = sizeof(char);
	do{
	printf("      Generic Linklist     \n");
	printf(" Insert Integer :  Press 1 \n");
	printf(" Insert Float   :  Press 2 \n");
	printf(" Insert Char    :  Press 3 \n");
	printf(" Print Integer  :  Press 4 \n");
	printf(" Print Float    :  Press 5 \n");
	printf(" Print Char     :  Press 6 \n");
	scanf("%d",&no);

	switch(no)
	{
		case 1:		for(i = 0; i < 5; i++)
					insert(&start, &arr[i], int_size);
				break;
		case 2:		for(i = 0; i < 4; i++)
					insert(&start, &arr2[i], float_size);
				break;
//		case 3:		insert(start, char_size);
//				break;
		case 4: 	print(start, printInt);
				break;
		case 5: 	print(start, printFloat);
				break;
		case 6: 	print(start, printChar);
				break;
		
					
	}
	}while(no != 100);
	
	
	return 0;
}	

/*void (*fptr) datanode()
{
	

}
*/

