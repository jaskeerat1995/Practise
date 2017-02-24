#include<stdio.h>
#include<stdlib.h>

#define SIZE 10

void merge_array(int *arr, int i1, int j1, int i2, int j2)
{	
	int i,j,n1,n2;
	int p,q,k;
	i = i1;
	j = i2;
	n1 = j1 -i1 + 1;
	n2 = j2 - j1;
	p = 0;
	q = 0;
	k = i1;

	int left[n1], right[n2];

	for(i = 0; i < n1; i++)
	{
		left[i] = arr[i1 + i];
		printf("left = %d at position %d\n",*(left + i),i);
	}

	for(j = 0; j < n2; j++)
	{
		right[j] = arr[i2 + j];
		printf("right = %d at position %d\n",*(right + j),j);
	}


	while(p < n1 && q < n2){
		if (left[p] <= right[q])
		{
			arr[k] = left[p];
			printf("arr in left = %d at %d\n",*(arr + k),k);
			p++;	
		}
		else
		{
			arr[k] = right[q];
			printf("arr in right = %d at %d\n",*(right + k),k);
			q++;	
		}
		k++;
	}

	//	if (i > n1)
	//	{
	while(q < n2)
	{
		arr[k] = right[q];
		printf("arr (j < n2) = %d at %d\n",*(arr + k),k);
		q++;
		k++;
	}
	//	}

	//	if (j > n2)
	//	{
	while(p < n1)
	{
		arr[k] = left[p];
		printf("arr (i < n1) = %d at %d\n",*(arr + k),k);
		p++;
		k++;
	}
	//	}	

	/*	for(i = i1,j=0; i <= j2; i++,j++)
		{
		arr[i] = temp[j];
		printf("arr = %d\n",*(arr + i));
		}
	 */	
	for(i = 0; i < SIZE; i++)
	{
		printf("%d\n",*(arr + i));
	}

}	

int merge_sort(int *arr, int a, int n)
{	
	int mid, i;	

	//n = sizeof(arr);
	printf("n before if()= %d\n",n);
	if (a < n)
	{
		printf("(n) = %d\n",n);
		mid = (a + n)/2;
		printf("mid = %d\n",mid);
		printf("a  = %d\n",a);
		merge_sort(arr,a,mid);
		printf("(n) after left = %d\n",n);
		printf("mid after left = %d\n",mid);
		merge_sort(arr,mid + 1, n);
		printf("(n) after right = %d\n",n);
		printf("mid after right = %d\n",mid);
		merge_array(arr,a,mid,mid+1,n);
		sleep(1);	
	}

	return 0;
}	

int main()
{	
	int *arr, i, mid, n;
	arr = (int *)malloc(sizeof(int) * SIZE);


	printf("Enter unsorted array1:\n");
	for(i = 0; i < SIZE; i++){
		scanf("%d",(arr + i));
	}
	n = SIZE;
	printf("n in main = %d\n",n);
	merge_sort(arr,0,n-1);
	printf("n in main21212 = %d\n",n);



	return 0;
}	



