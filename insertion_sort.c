#include<stdio.h>
#include<stdlib.h>
	
#define SIZE1  5
	
int * insertion_sort(int *a, int size)
{
	int i, k, temp;
	for(i = 1; i < size; i++)
	{
		temp = *(a + i);
		k = i;
		while (k > 0 && temp < *(a + k - 1))
		{
			*(a + k) = *(a + k - 1);
			printf("*(a + k) = %d\n",*(a + k));
			k = k -1;
		}
		*(a + k) = temp;
		printf("temp = %d\n",*(a + k));
	}
	
	return a;
}	
	
int main()
{	
	int *arr1, i, j;
	arr1 = (int *)malloc(sizeof(int) * SIZE1);	
		
	printf("Enter unsorted array1:\n");
	for(i = 0; i < SIZE1; i++)
	{
		scanf("%d",(arr1 + i));
	}
/*
	{
		printf("%d\n",*(arr1 + i));
	}
	
	for(i = 0; i < SIZE2; i++)
	{
		printf("%d\n",*(arr2 + i));
	}
*/	
	arr1 = insertion_sort(arr1,SIZE1);	
	printf("Sorted merged array:\n");	
	for(i = 0; i < SIZE1; i++)
	{
		printf("%d\n",*(arr1 + i));
	}
	
	
	return 0;
}	
	

