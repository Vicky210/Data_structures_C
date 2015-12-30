#include <stdio.h>
#include <stdlib.h>
struct Node {
   int data;
   struct Node* left;
   struct Node* right;
}
struct Node* Insert(struct Node* root,int x){
   if(root == NULL){
	struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
	temp->data = x;
	temp->left = NULL;
	temp->right = NULL;
	root = temp;
   }
   else if(x<=root->data)
	root->left = Insert(root->left,x);
   else
	root->right = Insert(root->right,x);
   return root;
}
bool Search(struct Node* root,int x){
   if(root == NULL)
	return false;
   else if(root->data = x)
	return true;
   else if(x<=root->data)
	return Search(root->left,x);
   else
	return Search(root->right,x);
}
int FindMin(struct Node* root){
   if(root == NULL){
	printf("\nThe tree is empty\n");
	return 0;
   }
   struct Node* temp = root;
   while(temp->left != NULL)	
	temp = temp->left;
   printf("\nthe minimum value is : %d\n",temp->data);
   return 0;
}
int FindMax(struct Node* root){
   if(root == NULL){
        printf("\nThe tree is empty\n");
        return 0;
   }
   struct Node* temp = root;
   while(temp->right != NULL)
        temp = temp->right;
   printf("\nthe maximum value is : %d\n",temp->data);
   return 0;
}
int FindMin_rec(struct Node* root){
   if(root == NULL){
        printf("\nThe tree is empty\n");
        return 0;
   }
   else if(root->left == NULL){
	printf("\nthe minimum value is : %d\n",root->data);
	return 0;
   }
   else
	return FindMin_rec(root->left);
}
int FindMax_rec(struct Node* root){
   if(root == NULL){
        printf("\nThe tree is empty\n");
        return 0;
   }
   else if(root->right == NULL){
        printf("\nthe maximum value is : %d\n",root->data);
        return 0;
   }
   else
        return FindMax_rec(root->right);
}

void main(){
   struct Node* root = NULL;
}
   
