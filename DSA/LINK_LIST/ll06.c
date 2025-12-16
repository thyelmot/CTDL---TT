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

void themDau(Node** head, int val){
    Node* newNode = createNode(val);
    newNode -> next = *head;
    *head = newNode;
}

void xoaDau(Node** head){
    if(*head == NULL) return;
    else{
        *head = (*head) -> next;
    }
}

int main(){
    int n, m;
    scanf("%d %d", &n, &m);
    Node* head = NULL;
    for(int i = 0; i < n; i ++){
        int val;
        scanf("%d", &val);
        themDau(&head, val);
    }
    for(int i = 0; i < m; i ++){
        xoaDau(&head);
    }
    printll(head);
    return 0;
}