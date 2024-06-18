#include<stdio.h>
#include<stdlib.h>

struct stack{
	int elem;
	struct stack *next;
}*top= NULL;

int isEmpty(){
	if(top==NULL)
		return 1;
	else
		return 0;
}

void push(int e){
	struct stack *newnode;
	newnode = malloc(sizeof(struct stack));
	newnode->elem = e;
	if(isEmpty())
		newnode->next = NULL;
	else
		newnode->next=top;
	top = newnode;
}

void pop(){
	if(!isEmpty()){
		struct stack *temp;
		temp = top;
		top = top->next;
		printf("\n%d\n",temp->elem);
		free(temp);
	}
	else
		printf("\nstack is underflow\n");
}

void peek(){
	if(isEmpty())
		printf("the stack is empty");
	else
		printf("%d",top->elem);
}

void display(){
	if(isEmpty())
		printf("\nstack is empty\n");
	else{
		struct stack *pos;
		pos = top;
		while(pos!=NULL){
			printf("%d ",pos->elem);
			pos=pos->next;
		}
	}
}

int main(){
	while(1){
		int n,e;
		printf("\nenter 1 for push\nenter 2 for pop\nenter 3 for peek\nenter 4 for display\n");
		printf("enter option : ");
		scanf("%d",&n);
		switch(n){
			case 0:
				exit(0);
				break;
			case 1:
				printf("enter element to push : ");
				scanf("%d",&e);
				push(e);
				display();
				break;
			case 2:
				pop();
				display();
				break;
			case 3:
				peek();
				break;
			case 4:
				display();
				break;
		}
	}
}
//STACK USING ARRAY
#include<stdio.h>
#include<stdlib.h>
int s=5,top=-1;
//printf("enter size of stack : ");
//scanf("%d",&s);
int arr[5];

void push(int e){
	 if(top!=s-1){
		top++;
		arr[top]=e;
	 }
	 else
		printf("the stack is overflow\n");
}

void pop(){
	if(top!=-1){
		printf("%d\n",arr[top]);
		top--;
	}
	else
		printf("the stack is underflow");
}

void peek(){
	if(top!=-1)
		printf("%d",arr[top]);
	else
		printf("the stack is empty");
}

void display(){
	for(int i=top;i>=0;i--)
		printf("%d ",arr[i]);
}

int main(){
	int n,e;
	while(1){
		printf("\nenter 1 for push\nenter 2 for pop\nenter 3 for peek\nenter 4 for display\n");
		printf("enter option: ");
		scanf("%d",&n);
		switch(n){
			case 0:
				exit(0);
				break;
			case 1:
				printf("enter element to push : ");
				scanf("%d",&e);
				push(e);
				display();
				break;
			case 2:
				pop();
				display();
				break;
			case 3:
				peek();
				break;
			case 4:
				display();
				break;
		}
	}
}