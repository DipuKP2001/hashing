#include <stdio.h>
#include <stdlib.h>
#define size 20
void insert(int d,int arr[]){
	int pos=d%size;
	if(arr[pos]==NULL){
		arr[pos]=d;
	}
	else{
		for(int i=1;i<size;i++){
			if(arr[(pos+i)%size]==NULL){
				arr[(pos+i)%size]=d;
				return;
			}
		}
	}
}
int search(int key,int arr[]){
	int pos=key%size;
	int flag=0;
	while(flag==0){
		for(int i=0;(i<size && (arr[(pos+i)%size]!=NULL));i++){
			if(arr[(pos+i)%size]==key){
				flag=1;
				return 1;
			}
		}
	}
}
void display(int arr[]){
	int i;
	printf("ELEMENTS IN THE ARRAY ARE:\n");
	for(i=0;i<size;i++){
		if(arr[i]){
			printf("Element:%d Position:%d\n",arr[i],i);
		}
	}
}
void main(){
	int arr[size];
	for(int i=0;i<size;i++){
		arr[i]=NULL;
	}
	int choice,elem;
	while(1){
		printf("Enter the choice 1.Insert 2.Search 3.Display 4.Exit\n");
		scanf("%d",&choice);
		switch(choice){
			case 1:
				printf("Enter the element to be inserted:\n");
				scanf("%d",&elem);
				insert(elem,arr);
				break;
			case 2:
				printf("Enter the element to be searched for:\n");
				scanf("%d",&elem);
				if(search(elem,arr)){
					printf("Element found\n");
				}
				else{
					printf("Element not found\n");
				}
				break;
			case 3:
				display(arr);
				break;
			case 4:
				printf("Exiting.....\n");
				exit(0);
			default:
				printf("Wrong choice\n");
				continue;
		}
	}
}
