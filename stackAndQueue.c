#include <stdlib.h>
#include <stdio.h>

struct Node* allocate(int val);
struct Node* enqueue(struct Node* head, int val);
struct Node* push(struct Node* head, int val);
struct Node* pop(struct Node* head);
void freeNodes(struct Node* head);
void printNodes(struct Node* head);


struct Node{
    int value;
    struct Node* next;
};

struct Node* allocate(int val){
    struct Node* temp = malloc(sizeof(struct Node));
    temp -> value = val;
    temp -> next = 0;
    return temp;

}
struct Node* enqueue(struct Node* head, int val){
	struct Node* temp = allocate(val);
	struct Node* ptr = head;
	if(head == 0){
		head = temp;
		return head;
	}
	while(ptr->next != 0){
		ptr = ptr->next;
	}
	ptr->next = temp;
	return head;

}
struct Node* push(struct Node* head, int val){
	struct Node* temp = allocate(val);
	if(head == 0){
		head = temp;
		return head;	
	}
	temp->next = head;
	head = temp;
	return head;
	
}
struct Node* pop(struct Node* head){
	
	struct Node* temp;
	temp = head;
	head = head->next;
	free(temp);
	if(head == 0){
		printf("EMPTY");
		return 0;
	}
	return head;
}
void freeNodes(struct Node* head){
	struct Node* temp;
	while(head != 0){
		temp = head;
		head=head->next;
		free(temp);
	
	}
	free(head);
}
void printNodes(struct Node* head){
	struct Node* ptr = head;
	
	while(ptr!=0){
		printf("%d ",ptr->value);
		ptr = ptr->next;
	}
	
	printf("\n");
	

}

int main(int argc, char* argv[argc+1]){
	if(argc < 2){
		printf("error\n");
		return EXIT_SUCCESS;
	}
	FILE* file = fopen(argv[1],"r");
	if(file == 0){
		printf("error\n");
		return EXIT_SUCCESS;
	}
	struct Node* head = 0;
	char str[11];
	int num;
		
	while(fscanf(file, "%s %d\n", str, &num) != EOF){
		if(str[1] == 'U'){
			head = push(head,num);
			printNodes(head);
		}else if(str[0] == 'E'){
			head = enqueue(head,num);
			printNodes(head);
		}else{
			if(head!=0){
			head = pop(head);
			printNodes(head);
			}else{
				printf("EMPTY\n");
			}
		}
	}
	
	freeNodes(head);
	fclose(file);
	return EXIT_SUCCESS;	
}
