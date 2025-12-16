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

void themdau(Node** head, int val){
    Node* newNode = createNode(val);
    newNode -> next = *head;
    *head = newNode;
}

void xoagiua(Node** head, int flag){
    if(*head == NULL) return;
    else{
        Node* tmp = *head;
        while(tmp -> next != NULL && tmp -> data != flag){
            tmp = tmp -> next;
        }
        if(tmp -> next != NULL){
            tmp -> next = tmp -> next -> next;
        }
    }
}

int main(){
    int n, m;
    scanf("%d %d", &n, &m);
    Node* head = NULL;
    for(int i = 0; i < n; i ++){
        int val;
        scanf("%d", &val);
        themdau(&head, val);
    }
    for(int i = 0; i < m; i ++){
        int flag;
        scanf("%d", &flag);
        xoagiua(&head, flag);
    }
    printll(head);
    return 0;
}