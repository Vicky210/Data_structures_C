#include<stdio.h>
#include<stdlib.h>
int maxsize=100,front = -1,rear = -1;
int queue[maxsize];
bool IsEmpty(){
	if(front == -1 && rear == -1)
		return true;
	else
		return false;
}
int Enqueue(int x){
	if((rear+1)%maxsize == front){
		printf("\nThe queue is full\n");
		return 0;
	}
	else if(IsEmpty()){
		front =0;
		rear = 0;
		queue[0] = x;
		return 0;
 	}
	rear = (rear+1)%maxsize;
	queue[rear] = x;
	return 0;
}
int Dequeue(){
	if(IsEmpty()){
		printf("\nThe queue is empty\n");
		return 0;
	}
	else if(front == rear){
		front = -1;
		rear = -1;
		return 0;
	}
	front = (front+1)%maxsize;
	return 0;
}	 
int front(){
	if(IsEmpty()){
                printf("\nThe queue is empty\n");
                return 0;
        }
	printf("\nThe element is : %d",queue[front]);
	return 0;
}
void main(){
}
