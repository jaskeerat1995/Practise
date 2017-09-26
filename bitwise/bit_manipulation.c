#include<stdio.h>

#define INT_BITS sizeof(int) * 8

enum bit_manipulation
{
	Binary_method1 = 1,
	Binary_method2,
	Binary_method3,
	Binary_method4,
	Binary_method5,
	Twos_compliment,
	Binary_to_integer,
	Rotate_bits,
	Operation_on_bits
};

void binary_method1(int);
void binary_method2(int);
void binary_method3(int);
void binary_method4(int);
void binary_method5(int);
void twos_compliment(int);
void binary_to_integer(int);
void rotate_bits(int);
void operations_on_bits(int);


int main()
{
	int no, num;
	
	do{
		printf("........BIT_MANIPULATIONS..........\n");
		printf("....Binary Representation Method 1...\n");
		printf("....Binary Representation Method 2...\n");
		printf("....Binary Representation Method 3...\n");
		printf("....Binary Representation Method 4...\n");
		printf("....Binary Representation Method 5...\n");
		printf("..........2's Compliment..............\n");
		printf(".........Binary to Integer.............\n");
		printf(".............Rotate bits................\n");
		printf("..........Operation on Bits..............\n");
		

		scanf("%d",&no);
		printf("Enter Integer:\n");
		scanf("%d",&num);
		
		switch(no)
		{
			case Binary_method1: 	binary_method1(num);
						break;
			case Binary_method2: 	binary_method2(num);
						break;
			case Binary_method3: 	binary_method3(num);
						break;
			case Binary_method4: 	binary_method4(num);
						break;
			case Binary_method5: 	binary_method5(num);
						break;
			case Twos_compliment:	twos_compliment(num);
						break;
			case Binary_to_integer:	binary_to_integer(num);
						break;
			case Rotate_bits:	rotate_bits(num);
						break;
			case Operation_on_bits:	operations_on_bits(num);
						break;
		}
	}while(no != 100);

}

void binary_method1(int no)
{
	int i, arr[INT_BITS];
	
	for(i = 0; i < INT_BITS; i++)
	{
		if(no & 1)
		{
			arr[i] = 1;
		}
		else
		{
			arr[i] = 0;
		}
		no = no >> 1;
	}

	for(i = INT_BITS - 1; i >= 0; i--)
	{
		printf("%d",arr[i]);
	}
	printf("\n");	

}

void binary_method2(int no)
{
	int i, arr[INT_BITS];

	for(i = 0; i < INT_BITS; i++)
	{
		arr[INT_BITS - i - 1] = ((no >> i) & 0x01);
	}

	for(i = 0; i < INT_BITS; i++)
	{
		printf("%d",arr[i]);
	}
	printf("\n");	

}

void binary_method3(int no)
{
	unsigned int i;

	for(i = (1 << 31); i > 0; i = i/2)
		(no & i)?printf("1"):printf("0");
	
	printf("\n");
}

void binary_method4(int no)
{


}

void binary_method5(int no)
{


}

void twos_compliment(int no)
{


}

void binary_to_integer(int no)
{


}

void rotate_bits(int no)
{


}

void operations_on_bits(int no)
{


}
