#include <stdlib.h>
#include <stdio.h>

int** buildMagicSquare(int n);
void printMS(int** mat, int n);
void freeMatrix(int** mat, int n);



int** buildMagicSquare(int n){
	int val = 1;
	int** mat = malloc((n)*sizeof(int*));
	for(int i = 0; i<n;i++){
		mat[i] = malloc((n)*sizeof(int));

	}
	int i = (n-1)/2;
	int j = 0;
	int a,b;
	while(val <= (n*n)){
		if(i > (n-1)){
			i = 0;
		}
		if(j<0){
			j = n-1;
		}
		
		mat[j][i] = val;
		
		val++;
		a = j-1;
		b = i+1;
		if(b>(n-1)){
			b = 0;
		}
		if(a<0){
			a = n-1;	
		}
		if(mat[a][b] == -1094795586){
			j--;
			i++;		
		}else{
			j++;
		}
		
	}
	return mat;

}

void printMS(int** mat, int n){

	for(int i = 0; i<n;i++){
		for(int j = 0;j<n;j++){

			printf("%d\t",mat[i][j]);

		}
		printf("\n");
	}
	
}
void freeMatrix(int** mat, int n){
	for(int i = 0; i < n; i++){
		free(mat[i]);
	}
	free(mat);
}
int main(int argc, char* argv[argc +1]){
	if(argc<2){
		printf("insufficient arguements");
		return EXIT_SUCCESS;
	}
	if(atoi(argv[1]) % 2 == 0){
		printf("error\n");
		return EXIT_SUCCESS;	
	}

	int n = atoi(argv[1]); 
	int** mat = buildMagicSquare(n);
	printMS(mat,n);
	freeMatrix(mat,n);

	return EXIT_SUCCESS;
}
