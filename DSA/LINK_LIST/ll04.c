#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;
}Node;

Node* createNode(int val){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode -> data = val;
    newNode -> next = NULL;
    return newNode;
}

void printll(Node* head){
    if(head != NULL){
        Node* tmp = head;
        do{
            printf("%d ", tmp -> data);
            tmp = tmp -> next;
        }while(tmp != head);
    }
}

void themDau(Node** head, int val){
    Node* newNode = createNode(val);
    if(*head == NULL){
        *head = newNode;
        newNode -> next = newNode;
    }
    else{
        Node* tmp = *head;
        while(tmp -> next != *head){
            tmp = tmp -> next;
        }
        newNode -> next = *head;
        tmp -> next = newNode;
        *head = newNode;
    }
}

int main(){
    int n;
    scanf("%d", &n);
    Node* head = NULL;
    for(int i = 0; i < n; i ++){
        int val;
        scanf("%d", &val);
        themDau(&head, val);
    }
    printll(head);
    return 0;
}