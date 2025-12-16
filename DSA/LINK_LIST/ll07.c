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

void xoaCuoi(Node** head, int m){
    for(int i = 0; i < m; i ++){
        if(*head == NULL) return;
        else if((*head) -> next == NULL){
            *head = NULL;
        }
        else{
            Node* tmp = *head;
            while(tmp -> next -> next != NULL){
                tmp = tmp -> next;
            }
            tmp -> next = NULL;
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
        themDau(&head, val);
    }
    xoaCuoi(&head, m);
    printll(head);
    return 0;
}