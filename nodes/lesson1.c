#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
	int data;
	struct Node *nextNode;

}node;
int main(){
	node *headNode, *secondNode, *thirdNode, *forthNode;
	
	
	headNode = (node*)malloc(sizeof(node));
	headNode->data = 1;
	
	
	secondNode = (node*)malloc(sizeof(node));
	secondNode->data = 2;
	headNode->nextNode = secondNode;
	
	secondNode->nextNode = thirdNode;
	
	
	thirdNode = (node*)malloc(sizeof(node));
	thirdNode->data = 3;
	
	secondNode->nextNode = thirdNode;
	
	
	forthNode = (node*)malloc(sizeof(node));
	forthNode->data = 4;
	
	thirdNode->nextNode = forthNode;
	
	while(headNode != NULL){
		printf("Value  : %d\n",headNode->data);
		headNode = headNode->nextNode;
	}
	
	
	return 0;
}
