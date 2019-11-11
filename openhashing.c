#include <stdio.h>
#include <stdlib.h>
typedef struct node{
	int data;
	struct node *link;
}Node;
int size;
void insert(int data,Node* arr[]){
	Node *newnode=(Node*)malloc(sizeof(Node));
	newnode->data=data;
	newnode->link=NULL;
	int pos=data%size;
	if(!arr[pos]){
		arr[pos]=newnode;
	}
	else{
		Node *temp=arr[pos];
		while(temp->link){
			temp=temp->link;
		}
		temp->link=newnode;
	}
}
int search(int key,Node* arr[]){
	int pos=key%size,flag=0;
	Node *temp=arr[pos];
	while(temp){
		if(temp->data==key){
			flag=1;
			break;
		}
		temp=temp->link;
	}
	return flag;
}
void display(Node* arr[]){
	for(int i=0;i<size;i++){
		if(arr[i]){
			printf("Elements in position %d are:\n",i);
			Node *temp=arr[i];
			while(temp){
				printf("%d ",temp->data);
				temp=temp->link;
			}
		}
		printf("\n");
	}
	printf("\n");
}
void main(){
	printf("Enter the size of array:\n");
	scanf("%d",&size);
        Node* arr[size];
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
     
