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


void main(){
   struct Node* root = NULL;
}
   
