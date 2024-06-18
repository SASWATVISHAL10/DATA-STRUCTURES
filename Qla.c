#include<stdio.h>
#include<stdlib.h>
int s=5;
int rear=-1;
int front=-1;
int arr[5];

void enqueue(int e){
	 if(rear!=s-1){
		rear++;
		arr[rear]=e;
		if(front == -1)
			front=0;
	 }
	 else
		printf("the queue is overflow\n");
}

void dequeue(){
	if(front!=-1){
		printf("%d\n",arr[front]);
		if(rear==front)
			front=rear= -1;
		else
			front++;
	}
	else
		printf("the queue is underflow\n");
}

void display(){
	if(front!=-1)
		for(int i=front;i<=rear;i++)
			printf("%d ",arr[i]);
	else
		printf("the queue is empty");
}

int main(){
	int n,e;
	while(1){
		printf("\nenter 1 for enqueue\nenter 2 for dequeue\nenter 3 for display\n");
		printf("enter option: ");
		scanf("%d",&n);
		switch(n){
			case 0:
				exit(0);
				break;
			case 1:
				printf("enter element to push : ");
				scanf("%d",&e);
				enqueue(e);
				display();
				break;
			case 2:
				dequeue();
				display();
				break;
			case 3:
				display();
				break;
		}
	}
}

//QUEUE IN LINKED LIST

#include<stdio.h>
#include<stdlib.h>

struct stack{
	int elem;
	struct stack *next;
}*rear= NULL,*front=NULL;

int isEmpty(){
	if(front==NULL)
		return 1;
	else
		return 0;
}

void enqueue(int e){
	struct stack *newnode;
	newnode = malloc(sizeof(struct stack));
	newnode->elem = e;
	newnode->next = NULL;
	if(rear == NULL)
		front = rear = newnode;
	else{
		rear->next = newnode;
		rear = newnode;
	}
}

void dequeue(){
	if(!isEmpty()){
		struct stack *temp;
		temp = front;
		front = front->next;
		printf("\n%d\n",temp->elem);
		free(temp);
	}
	else
		printf("\nqueue is underflow\n");
}

void display(){
	if(isEmpty())
		printf("\nqueue is empty\n");
	else{
		struct stack *pos;
		pos = front;
		while(pos!=NULL){
			printf("%d ",pos->elem);
			pos=pos->next;
		}
	}
}

int main(){
	while(1){
		int n,e;
		printf("\nenter 1 for enqueue\nenter 2 for dequeue\nenter 3 for display\n");
		printf("enter option : ");
		scanf("%d",&n);
		switch(n){
			case 0:
				exit(0);
				break;
			case 1:
				printf("enter element to push : ");
				scanf("%d",&e);
				enqueue(e);
				display();
				break;
			case 2:
				dequeue();
				display();
				break;
			case 3:
				display();
				break;
		}
	}
}