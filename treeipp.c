#include<stdio.h>
#include<stdlib.h>

struct node{
	struct node *left;
	int ele;
	struct node *right;
};

typedef struct node NODE;

NODE *insert(NODE *tree,int e){
	NODE *newnode = malloc(sizeof(NODE));
	if (tree != NULL){
		newnode->ele = e;
		newnode->left = NULL;
		newnode->right = NULL;
		tree = newnode;
	}
	else if(e<tree->ele)
		tree->left = insert(tree->left,e);
	else if(e>tree->ele)
		tree->right = insert(tree->right,e);
	return tree;
}

void preorder(NODE *tree){
	if(tree!=NULL){
		printf("%d",tree->ele);
		preorder(tree->left);
		preorder(tree->right);
	}
}
void inorder(NODE *tree){
	if(tree!=NULL){
		inorder(tree->left);
		printf("%d",tree->ele);
		preorder(tree->right);
	}
}
void postorder(NODE *tree){
	if(tree!=NULL){
		inorder(tree->left);
		preorder(tree->right);
		printf("%d",tree->ele);
	}
}

int main(){
	NODE *tree = NULL;
	int n,e,c;
	printf("enter a number of nodes in the tree : \n");
	scanf("%d",&n);
	printf("enter the elements\n");
	for(int i=1;i<=n;i++){
		scanf("%d",&e);
		tree=insert(tree,e);
	}
	do{
		printf("0.exit\t1.inorder\t2.preorder\t3.postorder\t");
		printf("enter the method");
		scanf("%d",&c);
		switch(c){
			case 0:
				exit(0);
				break;
			case 1:
				preorder(tree);
				break;
			case 2:
				inorder(tree);
				break;
			case 3:
				postorder(tree);
				break;
		}
	}while(c<3);
	return 0;
}