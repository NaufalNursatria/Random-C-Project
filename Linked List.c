#include <stdio.h>
#include <stdlib.h>

struct tnode{
    int value;
    struct tnode *next;
};
typedef struct tnode node;

node *inputList(node *head){
    node *newNode, *curr;
    while (1){
        newNode = (node*)malloc(sizeof(node));
        printf("Input number: ");
        scanf("%d", &newNode->value);
        
        if (newNode->value == -1){
            break;
        }
        
        newNode->next = NULL;
        if(head == NULL){
            head = newNode;
        } 
        else{
            curr = head;
            while(curr->next != NULL)
            {
                curr = curr->next;
            }
            curr->next = newNode;
        }
    }
    return head;
}

void printList(node *head){
    node *temp;
    temp = head;
    printf("Your list: ");
    while (temp->next != NULL){
        printf("%d ", temp->value);
        temp = temp->next;
    }
    printf("%d", temp->value);
}

int main(){
    node *head = NULL;
    head = inputList(head);
    printList(head);
    
    return 0;
}