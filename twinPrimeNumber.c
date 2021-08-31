#include <stdio.h>
#include <stdlib.h>

int isPrime(int num);


int isPrime(int num){

		
	for(int i = 2; i <= num/2; i++){
		if(num <= 1){
			return 0;
		}
		if(num % i == 0){
			return 0;

		}
	}
	
	return 1;
	
}
int main(int argc, char* argv[argc+1]){	
	if(argc < 2){
		printf("insufficient arguements\n");
		return EXIT_SUCCESS;
	}
	

	FILE* fp = fopen(argv[1], "r");
	int num;
	while(fscanf(fp, "%d\n" , &num) != EOF){
	
	if(num <= 2){
		printf("no\n");


	}else if(isPrime(num) == 1 && (isPrime(num + 2) == 1 || isPrime(num - 2) == 1)){

		printf("yes\n");
	}else{
		printf("no\n");
	}
	

	}

	
	


	
	fclose(fp);

	
	return EXIT_SUCCESS;
	


}
