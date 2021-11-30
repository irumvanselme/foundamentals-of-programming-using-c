#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
int age;
 struct Node *nextNode;
}n;


n* createNew(int data,n * previousNode){
n* new_node=(n*)malloc(sizeof(n));
new_node->age=data;


if(previousNode!=NULL)
previousNode->nextNode=new_node;
return new_node;
}


n* prepend(int data){
return createNew(data,NULL);
}



//Prepend: Create the head node
n* append(int data,n *previousNode){
if(previousNode==NULL){
printf("You can not append to a NULL node");
    exit(0);
}
n* newNode=createNew(data,previousNode);
return newNode;
}





//Append : Add to tail: Addition of a new node
//Insertion : Inserting a new nod between two consective nodes
//Deletion: remove a node from the list
//Travervasal : navigate through the list given the starting node



void traverser(n * startingNode){
	while(startingNode!=NULL){
	    printf("Ages : %d\n",startingNode->age);
	    startingNode=startingNode->nextNode;
	}
}



void inserter(n * startingNode,int data){
	n* previousNextNode=startingNode->nextNode;
	n* new_node=createNew(data,startingNode);
	new_node->nextNode=previousNextNode;
}

void deletebyData(n* *head,int data){
    n* deletable = *head, *previousNode;
    
    if(deletable->age == data){
        *head = deletable->nextNode;
        free(deletable);
        return;
    }
    
    // loop to find the deleted and the previous node
    
    while(deletable != NULL & deletable->age != data){
        previousNode = deletable;
        deletable = deletable->nextNode;   
    }
    
    // go to the last step
    
    if(deletable == NULL){
        return;
    }else{
        previousNode->nextNode = deletable->nextNode;
        free(deletable);
    }
}



int main(){
	n *headNode=prepend(1);
	n *secondNode=append(2,headNode);
	n *thirdNode=append(3,secondNode);
	n *fourthNode=append(4,thirdNode);
	// insertion in node
	inserter(thirdNode,55);
	deletebyData(&headNode,55);
	//END OF INSERTION
	// traversal
	traverser(headNode);
}
