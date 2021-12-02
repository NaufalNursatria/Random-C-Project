#include <stdio.h>
#include <stdlib.h>
#include<malloc.h>

struct tnode {
    int value;
    struct tnode *next;
}*head,*curr;

void pushHead(int angka){
    curr=(struct tnode*)malloc(sizeof(struct tnode));
    curr->value=angka;
    if(!head){
        curr->next=NULL;
    }
    else
    {
		curr->next = head;
		head = curr;
    }
    
}

void pop(){
	if(head == NULL){
		printf("Stack is Empty!!!\n");
	}
	else{
		struct tnode *temp=head;
		head = head->next;
		free(temp);
	}
}

int main(){
	pushHead(1);
	pushHead(2);
	pushHead(3);
	pushHead(4);
	pushHead(5);
	pushHead(6);
	pop(6);
	
	int i=1;
	while(curr!=NULL){

    printf("Nilai node ke-%d: %d\n",i,curr->value);
    printf("Alamat node ke-%d: %p\n",i,curr);
    printf("Isi next node ke-%d: %p\n\n",i,curr->next);
    curr=curr->next;
    i=i+1;
}
getchar();
}