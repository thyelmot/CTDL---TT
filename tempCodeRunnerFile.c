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
    if(*head == NULL){
        *head = newNode;
    }
    else{
        newNode -> next = *head;
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