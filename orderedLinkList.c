#include <stdlib.h>
#include <stdio.h>



struct Node* allocate(int val);
struct Node* insert(struct Node* head, int val);
struct Node* delete(struct Node* head,int val);
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

struct Node* insert(struct Node* head, int val){
	struct Node* temp = allocate(val);
	
	if(head == 0){
		head = temp;
		return head;
	}else if(val < head->value){
		temp-> next = head;
		head = temp;
		return head;
	}else{	
		
		struct Node* ptr = head;	     
		while(ptr->next != 0){
			if(ptr->value == val){
				free(temp);
				return head;
			}
			if(val < ptr->next->value){
				temp->next = ptr->next;
				ptr->next = temp;
				return head;
			}
			ptr=ptr->next;
		}
		
		ptr->next = temp;
		
	}
	return head;

}

struct Node* delete(struct Node* head, int val){
	

	struct Node* temp;
	if(head ==0){
		printf("EMPTY");
	}else if(head-> value == val){
		if(head-> next == 0){
			free(head);
			head = 0;
			printf("EMPTY");
			return head;
		}else{
			temp = head;
			head = head->next;
			free(temp);
			return head;

		}

	}



	for(struct Node* ptr = head; ptr != 0; ptr = ptr-> next){
		if(ptr-> value > val){
			return head;
		}
		if(ptr->value == val && ptr-> next == 0){
			struct Node* f = ptr->next;
			ptr = 0;
			free(f);
			break;
		}
		if(ptr-> next->value == val){
			struct Node* f = ptr->next;
			ptr->next = ptr->next->next;
			free(f);
			break;
		}

	}
	if(head->next == 0){
		printf("EMPTY");
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
	for(struct Node* ptr = head->next;ptr!=0;ptr=ptr->next){
		printf("%d ",ptr->value);	
	}
	printf("\n");


}
int main(int argc, char* argv[argc+1]){
	struct Node* head = allocate(0);
	FILE* fp = fopen(argv[1], "r");
	char* str = malloc(6*sizeof(char*));
	int val;
	while(fscanf(fp,"%s %d\n",str,&val) != EOF){
		if(*str == *("INSERT")){
			insert(head,val);
			printNodes(head);		
		}else{
			delete(head,val);
			printNodes(head);
		}
		
	}
	freeNodes(head);
	free(str);
	fclose(fp);
	
	return EXIT_SUCCESS;

}
	





