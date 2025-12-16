#include <stdio.h>
#define max 100000

typedef struct Srack{
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
    for(int i = s -> top; i >= 0; i --){
        printf("%d ", s -> a[i]);
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
        if(x == 2){
            int val;
            scanf("%d", &val);
            push(&s, val);
        }
        else if(x == 1){
            pop(&s);
        }
    }
    print(&s);
    return 0;
}