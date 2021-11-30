#include<stdio.h>
#include<stdlib.h>
typedef struct Node
{
    int data;
    struct Node *next;
}n;
int main(){ 
    system("clear");
    int p,u;
    n *head,*nextNode;
    head = NULL;
    head = (n*)malloc(sizeof(n));
    nextNode = (n*)malloc(sizeof(n));
    do{
        printf("1. Insert \n2. Read");
        scanf("%d",&p);
        if(p == 1){
            printf(" Enter the number :");
            scanf("%d",&u);
            nextNode->data = u;
            nextNode->next = head;
            head = nextNode;
        }else if(p == 2){
            nextNode = head;
            while(nextNode != NULL){
                printf("Data  : %d \n",nextNode->data);
                nextNode = nextNode->next;
            }
        }
    }while(p != -1);
    return 0;
}
