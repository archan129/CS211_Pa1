#include <stdio.h>
#include <stdlib.h>
int determinate(int** mat, int num);
int** readMatrix(FILE* fp);
void freeMatrix(int** mat, int n);
int main(int argc, char* argv[argc +1]);

int determinate(int** mat, int num){
	int det = 0;
	int sign =1;
	
	int** temp = malloc((num)*sizeof(int*));
	for(int i = 0; i<num;i++){
		temp[i] = malloc((num)*sizeof(int));
	}
	int n =0;
	int m = 0;
	if(num == 1){
		return mat[0][0];	
	}
	if(num == 2){
		det = (mat[0][0]*mat[1][1])-(mat[0][1]*mat[1][0]);	
		freeMatrix(temp,2);
		return det;	
	}
	for(int z = 0; z<num;z++){
		m=0;
		n=0;
		for(int i = 0; i<num;i++){
			for(int j =0;j<num;j++){
				temp[i][j] = 0;
				if(i!=0 && j!=z){
					temp[m][n] = mat[i][j];
					if(n<(num-2)){
						n++;					
					}else{
						n=0;
						m++;				
					}				
				}			
			}
		}


		det = det + sign * (mat[0][z] * determinate(temp,num-1));
		sign *= -1;	
		
				
	}
	
	freeMatrix(temp,num);

	return det;
}
int** readMatrix(FILE* fp){
	int n;
	fscanf(fp,"%d\n",&n);
	int** mat = malloc(n*sizeof(int*));
	for(int i = 0; i<n;i++){
		mat[i] = malloc(n*sizeof(int));
	}
	for(int i =0; i<n;i++){
		for(int j=0;j<n;j++){
			fscanf(fp,"%d",&mat[i][j]);
		}
		fscanf(fp,"\n");
	}
	
	return mat;
}
void freeMatrix(int** mat, int n){
	for(int i = 0; i < n; i++){
		free(mat[i]);
	}
	free(mat);
}

int main(int argc, char* argv[argc +1]){
	if(argc < 2){
		printf("insufficient arguements");
		return EXIT_SUCCESS;	
	}
	FILE* fp = fopen(argv[1], "r");
	//int val = atoi(argv[1]);






	int n;
	fscanf(fp,"%d\n",&n);
	int** mat = malloc(n*sizeof(int*));
	for(int i = 0; i<n;i++){
		mat[i] = malloc(n*sizeof(int));
	}
	for(int i =0; i<n;i++){
		for(int j=0;j<n;j++){
			//the \n in the next line may be an error, remove if neccecary.
			fscanf(fp,"%d",&mat[i][j]);
		}
		fscanf(fp,"\n");
	}




	int det = determinate(mat, n);
	printf("%d\n", det);

	

	fclose(fp);
	freeMatrix(mat,n);
		
	return EXIT_SUCCESS;
}
