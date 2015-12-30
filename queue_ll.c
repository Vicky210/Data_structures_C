#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* link;
};
struct Node* front;
struct Node* rear;
int Enqueue(int x){
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = x;
    temp->link = NULL;
    if(front == NULL && rear == NULL){
	front = temp;
	rear = temp;
	return 0;
    }
    rear->link = temp;
    rear = temp;
    return 0;
}
int dequeue(){
    if(front == NULL){
	printf("\nThe queue is empty\n");
	return 0;
    }
    if(front == rear){
	front = NULL;
	rear = NULL;
	return 0;
    }
    struct Node* temp = front;
    front = temp->link;
    free(temp);
}
int front(){
    if(front == NULL){
        printf("\nThe queue is empty\n");
        return 0;
    }
    printf("\nThe element is:%d",front->data);
    return 0;
}
int IsEmpty(){
   if(front == NULL)
	return 0;
   return -1;
}
void main(){
   front = NULL;
   rear = NULL;
}		 
