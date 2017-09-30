#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int** bit_pattern();
void set_bit_count();
void swap_bytes();
void binary_to_integer();

int main()
{
	char ch;
	do{
	   printf("BITS MANIPULATION MENU\n");
	   printf("Bits Pattern    :    Press 'p'\n");
	   printf("Swap bytes       :    Press 's'\n");
	   printf("No. of Set bit count      :    Press 'n'\n");
	   printf("Convert BtoI    :    Press 'c'\n");
	   printf("Reverse bits    :    Press 'r'\n");
	   printf("Set bits on particular position       :    Press 't'\n");
	   printf("To exit         :    Press 'e'\n");
	scanf(" %c",&ch);
	switch(ch)
	{
		case 'p': bit_pattern();
			  break;
		case 'n': set_bit_count();
			  break;
		case 'c': binary_to_integer();
			  break;
		
	}
	
	
	}while(ch != 'e');


	return 0;
}

int** bit_pattern()
{
	int no, arr[32],i,j,a;
	j = 31;
	printf("Enter no.\n");
	scanf("%d",&no);
	for(i = 0; i < 32; i++)
	{
		a = no & 0x01;
		arr[j] = a;
		//printf("arr[%d] = %d\n",j,arr[j]);
		no = no >> 1;
		j--;
	}
	printf("Bits pattern : \n");
	for(i = 0; i < 32; i++)
	{
		printf("%d",arr[i]);
	}
	printf("\n");
	
	return arr;
}

/*void binary_to_integer()
{
	
	int no, arr[32],i,j,a, count = 0, num, btoi=1, power=0, one = 1, btoi_prev = 0,result = 0;
	j = 31;
	int arr1[32];
	printf("Enter no.\n");
	scanf("%d",&no);
	num = no;
	for(i = 0; i < 32; i++)
	{
		if (i == 0)
		{
			power = 1;
		}
		else
		{
			power = i;
		}
		a = no & 0x01;
		if (a == 0)
		{
		arr[j] = a;
		j--;
		}
		else
		{
		count++;
		arr[j] = a;
//		btoi = btoi + pow(2,i);	
		printf("power: %d\n",power);
		while(power != 0)
		{
			printf("powerinwhile: %d\n",power);
			if(i == 0)
			{
				btoi_prev = 1;
				arr1[i] = btoi_prev;
				result = btoi_prev;
				printf("btoi_prev: %d\n",btoi_prev);
			}
			else
			{
				btoi = btoi *2;
				
				printf("btoi: %d\n",btoi);
			}	
		--power;
		}
		j--;
		//btoi = btoi/2;
		//printf("btoi/2: %d\n",btoi);
		result = result + btoi;
		btoi = 1;
		printf("result in while: %d\n",result);
		}
		no = no >> 1;
	}
	printf("No. of set bits in %d no integer is %d\n",num,count);
	printf("Bits pattern : \n");
	for(i = 0; i < 32; i++)
	{
		printf("%d",arr[i]);
	}
	printf("\n");
//	printf("binary into integer: btoi: %d\n",btoi);
	printf("binary into result : %d\n",result);

}*/

void binary_to_integer()
{
	
	int no, arr[33],i,j,a, count = 0, num, btoi=1, power=0,result = 0;
	j = 31;
	int arr1[33];
	printf("Enter no.\n");
	scanf("%d",&no);
	num = no;
	for(i = 0; i < 33; i++)
	{
		if (i == 0)
		{
			power = 1;
		}
		else
		{
			power = i;
		}
		a = no & 0x01;
		if (a == 0)
		{
		arr[j] = a;
		j--;
		}
		else
		{
		count++;
		arr[j] = a;
//		btoi = btoi + pow(2,i);	
//		printf("power: %d\n",power);
		while(power != 0)
		{
//			printf("powerinwhile: %d\n",power);
			if(i == 0)
			{
				btoi = 1;
//				printf("btoi_prev: %d\n",btoi);
			}
			else
			{
				btoi = btoi *2;
//				printf("btoi: %d\n",btoi);
			}	
		--power;
		}
		j--;
		result = result + btoi;
		btoi = 1;
	//	printf("result in while: %d\n",result);
		}
		no = no >> 1;
	}
	printf("No. of set bits in %d no integer is %d\n",num,count);
	printf("binary into integer result : %d\n",result);
	printf("Bits pattern : \n");
	for(i = 0; i < 32; i++)
	{
		printf("%d",arr[i]);
	}
	printf("\n");
//	printf("binary into integer: btoi: %d\n",btoi);

}

void swap_bytes()
{
	
}

void set_bit_count()
{

	int no, arr[32],i,j,a, count = 0, num;
	j = 31;
	printf("Enter no.\n");
	scanf("%d",&no);
	num = no;
	for(i = 0; i < 32; i++)
	{
		a = no & 0x01;
		if (a == 0)
		{
		arr[j] = a;
		j--;
		}
		else
		{
		count++;
		arr[j] = a;	
		j--;
		}
		//printf("arr[%d] = %d\n",j,arr[j]);
		no = no >> 1;
	}
	printf("No. of set bits in %d no integer is %d\n",num,count);
	printf("Bits pattern : \n");
	for(i = 0; i < 32; i++)
	{
		printf("%d",arr[i]);
	}
	printf("\n");

}
