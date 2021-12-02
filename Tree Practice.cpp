#include<stdio.h>
#include<stdlib.h>

struct tnode{
	struct tnode*left;
	struct tnode*right;
	int value;
};

void printAll(struct tnode*root){
    if (root != NULL) 
    { 
        printAll(root->left);
        printf("%d         %d\t%d\t%d\n",root,root->left,root->value,root->right);
        printAll(root->right); 
    }
}

struct tnode *tree = NULL;
int main(){
	int input;
	printf("input nilai: ");
	scanf("%d",&input);
	
	while (input != -1){
		printf("input nilai: ");
		scanf("%d",&input);
		
		struct tnode *ptr, *nodeptr, *parentptr;
		ptr=(struct tnode*) malloc(sizeof(struct tnode));
		ptr->left=NULL;
		ptr->value=input;
		ptr->right=NULL;
		
		//mengisi tree == NULL
		if(tree==NULL){
			tree=ptr;
			tree->left=NULL;
			tree->right=NULL;
		}
		else{
			parentptr=NULL;
			nodeptr=tree;
			//mengisi tree != NULL
			while(nodeptr!=NULL){
				parentptr=nodeptr;
				if(input<nodeptr->value){
					nodeptr=nodeptr->left;
				}
				else{
					nodeptr=nodeptr->right;
				}
			}
		}
		//parentptr kiri atau kanan jadi ptr
		if(input<parentptr->value){
			parentptr->left=ptr;
		}
		else{
			parentptr->right=ptr;
		}
	}
	printAll(tree);
}
