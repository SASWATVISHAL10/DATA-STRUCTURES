#include<stdio.h>
#include<stdlib.h>
struct node
{
    int e;
    struct node*next;
};
typedef struct node Node;
Node*front;
Node*rear;
void display()
{
    Node * position;
    position=front;
    if(position->next==NULL)
    {
        printf("stack is empty");
    }
    else
    {
        while(position->next!=NULL)
        {
            position=position->next;
            printf("%d ",position->e);
        }
        printf("\n");
    }
}
void enqueue()
{
    Node*newnode;
    newnode=malloc(sizeof(Node));
    printf("element to be insterted: ");
    scanf("%d",&newnode->e);
    newnode->next=NULL;
    rear->next=newnode;
    rear=newnode;
}
void dequeue()
{
   Node*position;
   position=rear;
   if(front->next==NULL)
   {
    printf("queue is underflow\n");
   }
   else
   {
    front=front->next;
   }
}
int main()
{
   int ch;
   front=malloc(sizeof(Node));
   front->next=NULL;
   rear=front;
   while(1){
    printf("1.enqueue\n2.dequeue\n3.exit\n");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1:enqueue();
		       display();
		       break;
		case 2:dequeue();
		       display();
		       break;
        case 3:exit(0);
		default:printf("invalid");
		        break;
	}
   }
}