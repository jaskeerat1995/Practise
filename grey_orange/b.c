#include<stdio.h>


int main()
{
	int i,j,N,k;
	
	scanf("%d",&N);
/*	for(i = 0; i < N; i++){
		for(j = N; j >= N-i; j--){
			printf("*");
		}
		printf("\n");
	}
*/
/*
	for(i = 0; i < N; i++){                      ///*****
		for(j = N; j > N-i; j--){            /// ****
			printf(" ");                 ///  ***
		}                                    ///   **
		for(k = j; k > 0; k-- ){             ///    *
			printf("*");
		}
		printf("\n");
	}
*/
	for(i = 0; i < N; i++){                      ///    *
		for(j = 0; j < N-1-i; j++){          ///   **
			printf(" ");                 ///  ***
		}                                    /// ****
		for(k = j; k < N; k++ ){             ///*****
			printf("*");
		}
		printf("\n");
	}

	return 0;
}
