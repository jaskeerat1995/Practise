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
	Operation_on_bits,
	Swap_nibble
};

void binary_method1(unsigned int);
void binary_method2(unsigned int);
void binary_method3(unsigned int);
void binary_method4(unsigned int);
void binary_method5(unsigned int);
void twos_compliment(unsigned int);
void binary_to_integer(unsigned int);
void rotate_bits(unsigned int);
unsigned int rotate_right(unsigned int);
unsigned int rotate_left(unsigned int);
void operations_on_bits(unsigned int);
void swap_nibble(unsigned int);


int main()
{
	int no;
	unsigned int num;
	
	do{
		printf("........BIT_MANIPULATIONS..........\n");
		printf("....Binary Representation Method 1..., \n");
		printf("....Binary Representation Method 2...\n");
		printf("....Binary Representation Method 3...\n");
		printf("....Binary Representation Method 4...\n");
		printf("....Binary Representation Method 5...\n");
		printf("..........2's Compliment..............\n");
		printf(".........Binary to Integer.............\n");
		printf(".............Rotate bits................\n");
		printf("..........Operation on Bits..............\n");
		printf(".............Swap Nibble..............\n");
		

		scanf("%d",&no);
		printf("Enter Integer:\n");
		scanf("%u",&num);
		
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
			case Swap_nibble:	swap_nibble(num);
						break;
		}
	}while(no != 100);

}

void binary_method1(unsigned int no)
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
		printf("%u",arr[i]);
		if (i % 8 == 0)
			printf(" ");
	}
	printf("\n");	

}

void binary_method2(unsigned int no)
{
	int i, arr[INT_BITS];

	for(i = 0; i < INT_BITS; i++)
	{
		arr[INT_BITS - i - 1] = ((no >> i) & 0x01);
	}

	for(i = 0; i < INT_BITS; i++)
	{
		printf("%u",arr[i]);
		if (i % 8 == 0)
			printf(" ");
	}
	printf("\n");	

}

void binary_method3(unsigned int no)
{
	unsigned int i;

	for(i = (1 << 31); i > 0; i = i/2)
		(no & i)?printf("1"):printf("0");
	
	printf("\n");
}

void binary_method4(unsigned int no)
{
	
	
}

void binary_method5(unsigned int no)
{
	
	
}

void twos_compliment(unsigned int no)
{
	
	
}
	
void binary_to_integer(unsigned int no)
{
	

}

void rotate_bits(unsigned int no)
{
	binary_method1(no);

	int num;
	unsigned int nos;
	printf("Rotate Right: Press 1\n");	
	printf("Rotate Left: Press 2\n");
	scanf("%d",&num);	
	switch(num)
	{
		case 1:		binary_method1(rotate_right(no));
				//binary_method1(nos);
				break;
		case 2:		rotate_left(no);
				break;
	}
	

}
	
unsigned int rotate_right(unsigned int no)
{
	int pos;

	printf("How many bits you want to rotate right\n");
	scanf("%d",&pos);

	return no >> pos | no << (32 - pos);			
}

unsigned int rotate_left(unsigned int no)
{
		
}

void operations_on_bits(unsigned int no)
{
	
	
}

void swap_nibble(unsigned int no)
{
	binary_method1(no);
	
	int i,j = 0;
	unsigned int arr[4] = {0xFFFFFF00,0xFFFF00FF,0xFF00FFFF,0x00FFFFFF};	

	for(i = 0; i < INT_BITS; i+=8){
	no = (((0xF0 << i) & no) >> 4) | (((0x0F << i) & no) << 4) | (no & arr[j]);
	j++;
	}

//	no = ((0xF0 & no) >> 4) | ((0x0F & no) << 4) | (no & arr[0]);

	printf("After swap..............\n");
	binary_method1(no);
}
