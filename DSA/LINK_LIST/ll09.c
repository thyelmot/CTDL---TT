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
    Node* tmp = head;
    do{
        printf("%d ", tmp -> data);
        tmp = tmp -> next;
    }while(tmp != head);
}

void themdau(Node** head, int val){
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
        tmp -> next = newNode;
        newNode -> next = *head;
        *head = newNode;
    }
}

void xoadau(Node** head){
    if(*head == NULL) return;
    else{
        Node* tmp = *head;
        while(tmp -> next != *head){
            tmp = tmp -> next;
        }
        *head = (*head) -> next;
        tmp -> next = *head;
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
        xoadau(&head);
    }
    printll(head);
    return 0;
}