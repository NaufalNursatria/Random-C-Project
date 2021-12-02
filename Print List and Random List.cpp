#include <stdio.h>
#include <stdlib.h>

struct node{
	int value;
	int key;
	struct node* next;
}*temp,*temp2, *select;
node* head = NULL;
node* head2 = NULL;

void InsertItem(int k, int v){
	node *temp = (node *) malloc (sizeof(node));
	node *temp2 = (node *) malloc (sizeof(node));
	temp->value = v;
	temp->key = k;
	temp->next = NULL;
	temp2->value = v;
	temp2->key = k;
	temp2->next = NULL;
	if (head == NULL){
		head = temp;
	}
	else{
		if (temp->key < head->key){
			temp->next = head;
			head = temp;
		}
		else{
			select = head;
			while (select->next != NULL && select->next->key < temp->key){
				select = select->next;
			}
			temp->next = select->next;
			select->next = temp;
		}
	}
	if (head2 == NULL){
		head2 = temp2;
	}
	else{
		if (temp2->value < head2->value){
			temp2->next = head2;
			head2 = temp2;
		}
		else{
			select = head2;
			while (select->next != NULL && select->next->value < temp2->value){
				select = select->next;
			}
			temp2->next = select->next;
			select->next = temp2;
		}
	}
}

void PrintAscending(node *head){
	select = head;
	do{
		printf("\nValue: ");
		printf("%d\n", select->value);
		printf("Key: ");
		printf("%d\n", select->key);
		select = select->next;
	}while (select != NULL);
}

void PrintUnsorted(node *head2){
	select = head2;
	do{
		printf("\nValue: ");
		printf("%d\n", select->value);
		printf("Key: ");
		printf("%d\n", select->key);
		select = select->next;
	}
	while (select != NULL);
}

int main(){
	int pilihan;
	int v;
	int k;
	do{
		printf("Menu \n 1.Insert Angka \n 2.Print List Ascending \n 3.Print List Acak \n 4.Exit");
		printf("\nMasukkan pilihan anda : ");
		scanf("%d",&pilihan);
		if (pilihan == 1){
			printf("Masukan Angka: ");
			scanf("%d",&v);
			printf("Masukan Key: ");
			scanf("%d",&k);
			InsertItem(k, v);
			printf("\n");
			printf("\n");
		}
		else if (pilihan == 2){
			printf("List Ascending: \n");
			PrintAscending(head);
			printf("\n");
			printf("\n");
		}
		else if (pilihan == 3){
			printf("List Acak: \n");
			PrintUnsorted(head2);
			printf("\n");
			printf("\n");
		}
		else if (pilihan == 4){
		break;
		}
	}
	while (pilihan != 4);
}
