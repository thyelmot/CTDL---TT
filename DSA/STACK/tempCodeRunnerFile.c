#include <stdio.h>
#define max 100000

typedef struct Stack{
    int a[max];
    int top;
}Stack;

void init(Stack* s){
    s -> top = -1;
}

void push(Stack* s, int val){
    if(s -> top != max -1){
        s -> top ++;
        s -> a[s -> top] = val;
    }
}

void pop(Stack* s){
    if(s -> top != -1){
        s -> top --;
    }
}

void print(Stack* s){
    if(s -> top != -1){
        printf("%d\n", s -> a[s -> top]);
    }
    else{
        printf("Empty!\n");
    }
}

int main(){
    int n;
    scanf("%d ", &n);
    Stack s;
    init(&s);
    for(int i = 0; i < n; i ++){
        int x;
        scanf("%d", &x);
        if(x == 1){
            int val;
            scanf("%d", &val);
            push(&s, val);
        }
        else if(x == 2){
            pop(&s);
        }
        else if(x == 3){
            print(&s);
        }
    }
    return 0;
}