#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* link;
};
struct Node* A;
int push(int x){
	struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = x;
    temp->link = NULL;
    struct Node* temp1 ;
    temp1 = A;
    while(temp1->link != NULL)
        temp1 = temp1->link;
    temp1->link = temp;
    return 0;
}
int pop(){
    if (A == NULL){
        printf("\nNothing to delete - The stack is empty");
        return 0;
    }
    struct Node* temp1,temp2 ;
    temp1 = A;
    temp2 = temp1->link;
    while(temp2->link != NULL){
        temp1 = temp1 ->link;
	temp2 = temp1->link;
    }
    printf("\nThe element popped is:%d\n",temp2->data);
    temp1->link = NULL;
    free(temp2);
    return 0;
}
int top(){
    if(A == NULL){
	printf("\nThe stack is empty\n");
	return 0;
    }
    struct Node* temp1 ;
    temp1 = A;
    while(temp1->link != NULL)
        temp1 = temp1 ->link;
    printf("\nThe element is:%d\n",temp1->data);
    return 0;
}
int isEmpty(){
   if(A == NULL){
        printf("\nThe stack is empty\n");
        return 0;
    }
    printf("\nThe stack is not empty\n");
    return 0;
}
void main(){
}	
