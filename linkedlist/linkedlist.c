#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
	int val;
	struct Node *next;

} Node;

void cleanNode(Node *node){
	node->val = NULL;
	node->next = NULL;
}

int push_back(Node *head, int val){

	if(head==NULL){
		printf("no head passed");
		return -1;
	}	
	
	Node *temp = head;

	while(temp->next!=NULL){
		temp = temp->next;
	}

	Node *newNode = (struct Node *) malloc(sizeof(struct Node));
	cleanNode(newNode);
	newNode->val = val;

	temp->next = newNode;
	return 1;
}

int delete_back(Node *head){

	if(head==NULL){
		printf("no head passed");
		return -1;
	}

	Node* tempPrev = NULL;
	Node *temp = head;

	while(temp->next!=NULL){
		tempPrev = temp;
		temp = temp->next;
	}

	Node *prev = tempPrev;
	tempPrev = tempPrev->next;

	prev->next = NULL;
	free(tempPrev);

	return 1;
}



typedef struct{
	Node *head;

} LinkedList;


int lappend(LinkedList *lst,int val){

	if(lst->head==NULL){
		Node *head = (struct Node *) malloc(sizeof(struct Node));

		cleanNode(head);

		head->val = val;
	  	lst->head = head;
		return 1;	
	}

	push_back(lst->head,val);
	return 1;

}

int ldelete(LinkedList *lst){
	if(lst->head==NULL){
		printf("list is empty");
		return -1;
	}
	if(lst->head->next==NULL){
		Node *temp = lst->head;
		lst->head = NULL;
		free(temp);
		return 1;
	}
	
	delete_back(lst->head);
	return 1;

}


void printLst(LinkedList *lst){

	Node *temp;
	temp = lst->head;

	while(temp!=NULL){
		printf("%d -> ",temp->val);
		temp = temp->next;
	}
	printf("NULL\n");
}

int main(){
	
	LinkedList mylist = {NULL};

	lappend(&mylist,2);

	lappend(&mylist,3);
	lappend(&mylist,4);

	ldelete(&mylist);
	ldelete(&mylist);
	

	printLst(&mylist);

	return 0;

}