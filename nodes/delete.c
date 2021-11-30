#include<stdio.h>
typedef struct theList{
    int data ;
    struct theList *next;
}list;
list* deletebyData(*head,int data){
    list * deletable = *head, previousNode;
    
    // check if data is not on the head
    
    if(deletable->data == data){
        *head = deletable->next;
        free(deletable);
        return;
    }
    
    // loop to find the deleted and the previous node
    
    while(deletable != NULL & deletable->data != data){
        previousNode = deletable;
        deletable = deletable->next;   
    }
    
    // go to the last step
    
    if(deletable == NULL){
        return
    }else{
        previousNode->next = deletable->next;
        free(deletable)
    }
    return head;
}
int main(){
    printf(" \n 1. Insert \n 2. View \n 3. Delete  \n   Enter your choice  : ");
    return 0;
}
