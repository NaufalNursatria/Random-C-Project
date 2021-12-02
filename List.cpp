#include <stdio.h>
#include <stdlib.h>

struct node{
 int value;
 struct node *next;
};

struct node* head = NULL;

void insertList(){
 int valx;
 struct node *newNode,  *ptr;
 printf("\nMasukkan nilai : ");
 scanf("%d",&valx); 
 while (valx !=-1){
  struct node* newNode=(struct node*)malloc(sizeof(struct node));
  newNode->value = valx;
  newNode->next = NULL;
  if (head == NULL){
   head = newNode;
  }
  else {
   ptr = head;
   while (ptr->next != NULL){
    ptr = ptr->next ;
   }
   newNode->next = ptr->next;
   ptr->next = newNode;
  }
  printf("\nMasukkan Nilai : ");
  scanf("%d",&valx);
 }
}

void deleteFirstNode(){
    struct node *del;
 printf("Deleting first node");
    if(head == NULL)
    {
        printf("No Data");
    }
    else
    {
        del = head;
        head = head->next;
        printf("\nData deleted = %d\n", del->value);
        free(del);
    }
}


void printList(){
 struct node *ptr;
 ptr = head;
 while (ptr->next != NULL){
  printf("%d > ",ptr->value);
  ptr = ptr->next;
 }
 printf("%d",ptr->value);
 printf("\n");
}

void insertAfter(){
 int insert, after;
 struct node* newNode=(struct node*)malloc(sizeof(struct node));
 printf("Insert after\n");
 printf("Masukkan data yang diinginkan: ");
 scanf("\n%d", &insert);
 printf("data sekarang : ");
 printList();
 printf("Setelah data : ");
 scanf("%d", &after);
 newNode->value = insert;
 if (head == NULL){
  newNode->next=NULL;
  head=newNode;
 }
 else if(head->value == after){
   newNode->next = head->next;
   head->next = newNode;
  }
  else{
   struct node* ptr = head;
   while (ptr->next->value != after){
    ptr = ptr->next;
    newNode->next = ptr->next->next;
    ptr->next->next=newNode;
   }
  }
 }

void deletemultiple(){
  int x;
  struct node* ptr = head;
  struct node* del;
  while (head->value == x) {
        head = head->next;
        free(ptr);
        ptr = head;
    }
    while (ptr->next != NULL) {
        if (ptr->next->value == x) {
            del = ptr->next;
            if (ptr->next->next != NULL) ptr->next = ptr->next->next;
            else ptr->next = NULL;
            free(del);
        }
        else ptr = ptr->next;
    }
}

int main(){
 insertList();
 printList();
 deleteFirstNode();
 printList();
 insertAfter();
 printList();
  deletemultiple();
  printList();
}