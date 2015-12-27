#include<stdio.h>
#include<stdlib.h>
int maxsize=100,top=-1;
int *stack;
void init(){
	stack = malloc(maxsize*sizeof(int));
}
int push(int x){
	if(top<maxsize){
		top++;
		stack[top]=x;
		return 0;
	}
	maxsize=maxsize*2;
	stack = realloc(stack,maxsize*sizeof(int));
	top++;
	stack[top]=x;
	return 0;
}
int pop(){
	if(top == -1){
		printf("\nThe stack is empty\n");
		return 0;
	}
	printf("\nThe element popped:%d",stack[top]);
	top--;
	return 0;
}
int top_f(){
        if(top == -1){
                printf("\nThe stack is empty\n");
                return 0;
        }
	printf("\nThe element is:%d",stack[top]);
	return 0;
}
int isEmpty(){
        if(top == -1){
                printf("\nThe stack is empty\n");
                return 0;
        }
	printf("\nThe stack is not empty\n");
}
void main(){
	init();
}
