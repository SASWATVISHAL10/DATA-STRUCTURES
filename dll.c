#include <stdio.h>
#include <stdlib.h>
struct node{
	struct node *prev;
    int elem;
    struct node *next;
};

int isEmpty(struct node *list){
	if(list->next == NULL)
		return 1;
	else
		return 0;
}
struct node *find(struct node *list,int f){
	struct node *pos;
	pos = list->next;
	while(pos->elem!=f&&pos->next!=NULL)
		pos = pos->next;
	return pos;
}

struct node *findprev(struct node *list,int f){
	struct node *pos;
	pos = list->next;
	while(pos->next->elem!=f&&pos->next!=NULL)
		pos = pos->next;
	return pos;
}

void insbeg(struct node *list,int e){
    struct node *newnode;
    newnode = malloc(sizeof(struct node));
    newnode->elem = e;
    if (list->next == NULL){
        newnode->next = NULL;
	}
    else
        newnode->next = list->next;
    list->next = newnode;
	newnode->prev = list;
}

void insmid(struct node *list,int p,int e){
	struct node *newnode,*temp,*pos;
	pos = find(list,p);
	temp = pos->next;
	newnode=malloc(sizeof(struct node));
	newnode->elem=e;
	newnode->next = pos->next;
	pos->next = newnode;
	temp->prev=newnode;
	newnode->prev = pos;
}

void inslas(struct node *list,int e){
	struct node *newnode,*pos;
	pos = list;
	newnode = malloc(sizeof(struct node));
	newnode->elem = e;
	newnode->next = NULL;
	while(pos->next!=NULL)
		pos = pos->next;
	pos->next = newnode;
	newnode->prev = pos;
}

void delbeg(struct node *list){
	if(!isEmpty(list)){
		struct node *temp;
		temp = list->next;
		list->next=temp->next;
		temp->next->prev = list;
		free(temp);
	}
	else
		printf("list is empty");
}

void delmid(struct node *list,int p){
	if(list->next!=NULL){
		struct node *pos,*temp;
		pos = findprev(list,p);
		temp = pos->next;
		pos->next = temp->next;
		temp->next->prev = pos;
		free(temp);
	}
	else
		printf("list is empty");
}

void dellas(struct node *list){
	if(list->next!=NULL){
		struct node *pos,*temp;
		pos = list;
		while(pos->next->next!=NULL)
			pos=pos->next;
		temp = pos->next;
		pos->next = NULL;
		free(temp);
	}
	else
		printf("list is empty");
}

void display(struct node *list){
    if (list->next != NULL){
		struct node *pos;
		pos = list;
		while(pos->next != NULL){
			pos = pos->next;
			printf(" %d",pos->elem);
		}
	}
}
int main() {
    int n,b,m,p,l,f,md;
	struct node *list;
	list = malloc(sizeof(struct node));
	list->next = NULL;
	list->prev = NULL;
    while(1){
        printf("\nenter 1 for insert beginning\nenter 2 for insert middle\nenter 3 for insert last\nenter 4 for delete beginning\nenter 5 for delete at middle\nenter 6 for delete at last\nenter 7 for display\n");
        printf("\nenter option: ");
        scanf("%d",&n);
        switch(n){
            case 0:
                exit(0);
                break;
            case 1:
                printf("enter element to insert at beg : ");
                scanf("%d",&b);
                insbeg(list,b);
				display(list);
                break;
			case 2:
				printf("enter element to insert at mid : ");
				scanf("%d",&m);
				printf("enter position of element after : ");
				scanf("%d",&p);
				insmid(list,p,m);
				display(list);
				break;
			case 3:
				printf("enter element to insert at last: ");
				scanf("%d",&l);
				inslas(list,l);
				display(list);
				break;
			case 4:
				delbeg(list);
				display(list);
				break;
			case 5:
				printf("enter element to delete in middle: ");
				scanf("%d",&md);
				delmid(list,md);
				display(list);
				break;
			case 6:
				dellas(list);
				display(list);
				break;
			case 7:
				display();
				break;
        }
    }

    return 0;
}