#include<stdio.h>
#include<stdlib.h>
	
#define SIZE1  5
#define SIZE2  7
	
int * merge(int *a, int *b)
{	
	int *c = (int *) malloc(sizeof(int) * (SIZE1 + SIZE2));
	int i, j, k;
	i = j = k = 0;
		
	while(i < SIZE1 && j < SIZE2)
	{	
		if(*(a + i) <= *(b + j))
		{
			*(c + k) = *(a + i);
			k++;
			i++;
		}
		else
		{
			*(c + k) = *(b + j);
			k++;
			j++;
		}
	}
	
	if(i >= SIZE1)
	{	
		while (j < SIZE2)
		{
			*(c + k) = *(b + j);
			k++;
			j++;
		}
	}	
	
	if(j >= SIZE2)
	{	
		while (i < SIZE1)
		{
			*(c + k) = *(a + i);
			k++;
			i++;
		}
	}		
		
	return c;
}	
	
int * sort(int *a, int size)
{
	int i, j, temp;
	for(i = 0; i < size; i++)
	{
		for(j = 0; j < (size - i - 1); j++)
		{
			if(*(a + j) > *(a + j + 1))
			{
				temp = *(a + j);
				*(a + j) = *(a + j + 1);
				*(a + j + 1) = temp;
			}	
		}
	}
	
	return a;
}

int main()
{	
	int *arr1, *arr2, *arr3, i, j;
	arr1 = (int *)malloc(sizeof(int) * SIZE1);	
	arr2 = (int *)malloc(sizeof(int) * SIZE2);
	
	
	printf("Enter unsorted array1:\n");
	for(i = 0; i < SIZE1; i++)
	{
		scanf("%d",(arr1 + i));
	}

	printf("Enter unsorted array2:\n");
	for(i = 0; i < SIZE2; i++)
	{
		scanf("%d",(arr2 + i));
	}
			
/*	for(i = 0; i < SIZE1; i++)
	{
		printf("%d\n",*(arr1 + i));
	}
	
	for(i = 0; i < SIZE2; i++)
	{
		printf("%d\n",*(arr2 + i));
	}
*/	
	arr1 = sort(arr1,SIZE1);	
	arr2 = sort(arr2,SIZE2);	
	arr3 = merge(arr1,arr2);
	printf("Sorted merged array:\n");	
	for(i = 0; i < (SIZE1 + SIZE2); i++)
	{
		printf("%d\n",*(arr3 + i));
	}
	
	
	
	return 0;
}	
	
	
	
