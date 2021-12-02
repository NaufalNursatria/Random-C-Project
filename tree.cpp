#include<stdio.h>
#include<stdlib.h>

struct node{ 
    int value; 
    struct node *left,*right; 
}; 

struct node*createNode(int data){
	struct node*newNode;
	newNode = (node *) malloc(sizeof(node));
    newNode->value = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void printAll(struct node *root){
    if (root != NULL) 
    { 
        printAll(root->left);
        printf("%d         %d\t%d\t%d\n",root,root->left,root->value,root->right);
        printAll(root->right); 
    }
}

struct node*insert(struct node* node, int value){ 
    if (node == NULL){
        return createNode(value); 
    }
    if (value < node->value){
        node->left  = insert(node->left, value); 
    }
    else if (value > node->value){
        node->right = insert(node->right, value);    
    }
    return node; 
} 

struct node*minValueNode(struct node* node){ 
    struct node* current = node; 
    while (current && current->left != NULL){
        current = current->left;
	}
    return current; 
} 

struct node*deleteNode(struct node* root, int value){ 
    if (root == NULL){ 
	return root;
	}
    if (value < root->value){
        root->left = deleteNode(root->left, value);
	}
    else if (value > root->value){
        root->right = deleteNode(root->right, value);
	}
    else{
        if (root->left == NULL){ 
            struct node *temp = root->right; 
            free(root); 
            return temp; 
        } 
        else if (root->right == NULL){ 
            struct node *temp = root->left; 
            free(root); 
            return temp; 
        } 
        struct node* temp = minValueNode(root->right); 
        root->value = temp->value; 
        root->right = deleteNode(root->right, temp->value); 
    } 
    return root; 
} 

int main() 
{ 
    struct node *root=NULL; 
    root = insert(root,50); 
    insert(root,30); 
    insert(root,20); 
    insert(root,40); 
    insert(root,70); 
    insert(root,60); 
    insert(root,80);
    printAll(root);  
    printf("\nDelete 20\n"); 
    root = deleteNode(root, 20); 
    printAll(root); 
    return 0; 
} 


