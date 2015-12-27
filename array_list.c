#include<stdio.h>
#include<stdlib.h>
int maxsize=100,end=-1;
int *list;
void init(){
	list = malloc(maxsize*sizeof(int));
}
int insert_end(int x){
	if(end<maxsize){
		end++;
		list[end]=x;
		return 0;
	}
	maxsize=maxsize*2;
	list = realloc(list,maxsize*sizeof(int));
	end++;
	list[end]=x;
	return 0;
}
int delete_end(){
	if(end!=-1){
		end--;
		return 0;
	}
	printf("No elements in the list to delete");
	return 0;
}
int print_n(int n){
	if(end>=n){
		printf("\nElement at position %d is:%d\n",n,list[n]);
		return 0;
	}
	printf("\nNo element at position %d\n",n);
	return 0;
}
int insert(int x,int n){
	if(end==(n-1)){
		insert_end(x);
		return 0;
	}
	if(end>=n){
		if(end==maxsize){
			maxsize=maxsize*2;
			list = realloc(list,maxsize*sizeof(int));
		}
		int j=end;
		end++;
		int i=end;
		while(j>=n){
			list[i]=list[j];
			j--;
			i--;
		}
		list[n]=x;
		return 0;
	}
	printf("\nCant insert at position %d\n",n);
	return 0;
}
int delete(int n){
	if(end<n){
		printf("\nNo element at position %d\n",n);
		return 0;
	}
	if(end ==n){
		end--;
		return 0;
	}
	int j=n;
	int i=n+1;
	while(i<=end){
		list[j]=list[i];
		i++;
		j++;
	}
	end--;
	return 0;
}
int print(){
	if(end==-1){
		printf("\nThe list is empty!\n");
		return 0;
	}
	int i=0;
	printf("\nThe elements in the list are:%d->",list[i]);
	while(i>end){
		i++;
		printf("%d->",list[i]);
	}
	return 0;
}
void main(){
}
