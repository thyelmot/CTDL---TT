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
        while(tmp != NULL){
            printf("%d ", tmp -> data);
            tmp = tmp -> next;
        }
    }
}

void themGiua(Node** head, int val, int flag){
    Node* newNode = createNode(val);
    if(*head == NULL){
        *head = newNode;
    }
    else{
        Node* tmp = *head;
        while(tmp -> next != NULL && tmp -> data != flag){
            tmp = tmp -> next;
        }
        if(tmp -> data == flag){
            newNode -> next = tmp -> next;
            tmp -> next = newNode;
        }
        else{
            newNode -> next = *head;
            *head = newNode;
        }
    }
}

int main(){
    int n;
    scanf("%d", &n);
    Node* head = NULL;
    for(int i = 0; i < n; i ++){
        int val, flag;
        scanf("%d %d", &val, &flag);
        themGiua(&head, val, flag);
    }
    printll(head);
    return 0;
}