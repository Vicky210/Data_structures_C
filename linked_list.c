#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* link;
};
struct Node* A;
void insert_end(){
    int x;
    printf("\nEnter the data to insert:");
    scanf("%d",&x);
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = x;
    temp->link = NULL;
    struct Node* temp1 ;
    temp1 = A;
    while(temp1->link != NULL)
        temp1 = temp1->link;
    temp1->link = temp;
    menu();
}
void insert_start(){
    int x;
    printf("\nEnter the data to insert:");
    scanf("%d",&x);
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data =x;
    if(A != NULL)
        temp->link = A;
    else
        temp->link = NULL;
    A = temp;
    menu();
}
void insert_n() {
    int x,n;
    printf("\nEnter the data to insert:");
    scanf("%d",&x);
    printf("\nEnter the position to insert:");
    scanf("%d",&n);
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    if (A == NULL || n==1){
        insert_start(x);
        menu();
    }   
    temp->data = x;
    temp->link = NULL;
    int i=1;
    struct Node* temp1 ;
    temp1 = A;
    while(temp1->link != NULL){
        if(i ==(n-1))
            break;
        temp1 = temp1->link;
        i++;
    }
    if(temp1->link != NULL)    
        temp->link = temp1->link;
    temp1->link = temp;
    menu();
}
void delete(){
    int n;
    printf("\nEnter the position to delete:");
    scanf("%d",&n);
    if (A == NULL){
        printf("\nNothing to delete - The list is empty");
        menu();
    }
    struct Node* temp1 ;
    temp1 = A;
    if(n==1){
        A = temp1->link;
        free(temp1);
        menu();
    }
    int i=1;
    while(i != (n-1)){
        if(temp1->link == NULL){
            printf("\nThere is no element to delete in position %d",n);
            menu();
        }
        temp1 = temp1->link;
        i++;
    }
    if(temp1->link == NULL){
            printf("\nThere is no element to delete in position %d",n);
            menu();
        }
    struct Node* temp2;
    temp2 = temp1->link;
    temp1->link =temp2->link;
    free(temp2);
    menu();
}
void print() {
    struct Node* temp1 ;
    temp1 = A;
    printf("\nElements in the list are : \n");
    while(temp1->link != NULL)
    {
        printf("%d -> ",temp1->data);
        temp1 = temp1 ->link;
    }
    printf("%d",temp1->data);
    menu();
}
void reverse(){
    struct Node* current;
    struct Node* prev;
    struct Node* next;
    current=A;
    //prev = NUL
    while(current->link != NULL){
        next = current->link;
        current->link = prev;
        prev = current;
        current = next;
    }
    A = prev;
    menu();
}
void reverse_recursive(struct Node* p){
    if(p->link == NULL){
	A= p;
	return;
    }
    reverse_recursive(p->link);
    struct Node* q = p->link;
    q->link = p;
    p->link = NULL;
}
void print1(struct Node* p){
    if(p == NULL)
        menu();
    printf("%d->",p->data);
    print1(p->link);
}
void menu(){
    char choice;
    if (A== NULL){
        printf("\nList is empty, you can insert an element. Do you want to :y or n?");
        scanf("%c",&choice);
        if(choice == 'y' || choice == 'Y'){
            insert_start();
            return;
        }
        else
            return;
    }
    int c = 0;
    printf("\nMenu(select your choice):\n 1.Insert at head\t 2.Insert at end\t 3.Insert at a position\t 4.Delete an element\t 5.Reverse linked list\t 6.Print\t 6.Exit\n");
    scanf("%d",&c);
    switch(c){
        case 1: insert_start();
                break;
        case 2: insert_end();
                break;
        case 3: insert_n();
                break;
        case 4: delete();
                break;
        case 5: reverse();
                break; 
        case 6: print();
                break;
        case 7: printf("\nExiting....");
                break;
        default: printf("\nWrong choice");
                 menu();
                
    }
    return;
}
void main() {
    A=NULL;
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    menu();
}


