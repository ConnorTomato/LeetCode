- C语言实现栈

```c
#include<stdio.h>
#include<stdlib.h>
typedef struct node* Node;
typedef struct stack* Stack;
struct node{
    int data;
    struct node *next;
};
struct stack{
    Node Top;
    Node Base;
};

Stack InitStack(Stack s);
void Push(Stack s, int val);
void Pop(Stack s);
int isEmpty(Stack s);
void Print(Stack s);
void clearStack(Stack s);

Stack InitStack(Stack s){
    s->Base = (Node)malloc(sizeof(struct node));
    if(!s->Base){
        printf("Memory allocation failure");
		exit(-1);
    }
    s->Top = s->Base;
    s->Top->data = 0;
    s->Top->next = NULL;
    return s;
}

void Push(Stack s, int val){
    Node node = (Node)malloc(sizeof(struct node));
    if(!node){
        printf("Memory allocation failure");
		exit(-1);
    }
    node->next = s->Top;
    node->data = val;
    s->Top = node;
}

void Pop(Stack s){
    if(isEmpty(s)){
        printf("Stack is Empty");
        return;
    }else{
        Node p = s->Top;
        s->Top = s->Top->next;
        free(p);
        p = NULL;
    }
}

int isEmpty(Stack s){
    if(s->Top == s->Base){
        return 1;
    }else
    {
        return 0;
    }
    
}
void Print(Stack s){
    Node p = s->Top;
    while(p != s->Base){
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

void clearStack(Stack s){
    if(isEmpty(s)){
        return;
    }else{
        Node p = NULL;
        while(s->Top != s->Base){
            p = s->Top;
            s->Top = s->Top->next;
            free(p);
            p = NULL;
        }
    }
}

int main(){
    Stack s = InitStack(s);
    for(int i = 0; i < 2; i++){
        int n;
        printf("i:");
        scanf("%d",&n);
        Push(s, n % 8);
    }
    Print(s);
    return 0;
}

```

