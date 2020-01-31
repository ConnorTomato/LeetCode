#include<stdio.h>
#include<stdlib.h>

struct link {
    int data;
    struct link*next;
};



struct link*Creat(int n){
    struct link*head,*node,*end;
    head = (struct link *)malloc(sizeof(struct link ));
    end = head;
    for(int i = n; i>0; i--){
    node  = (struct link *)malloc(sizeof(struct link ));
    printf("Input data:");
    scanf("%d",&node->data);
    end->next = node;
    end = node;
    }
    end->next = NULL;
    return head;
}

void Print(struct link*head){
    struct link*p = head;
    int i = 1;
    p = p->next;
    while(p!=NULL)
    {
        printf("%d\t%d\n",i,p->data);
        p = p->next;
        i++;
    }
    
}


void Delete(struct link*head,int number ){
    struct link *p = head,*pr = head;
    int i = 0;
    while(i<number && p!=NULL){
        pr =p;
        p = p->next;
        i++;
    }
    if(p!=NULL){
        pr->next = p->next;
        free(p);
    }
    else{
        printf("not exist!\n");
    }

}

void Insert(struct link *head,int n){
    struct link *p = head,*pr;
    pr = (struct link*)malloc(sizeof(struct link ));
    printf("Input data:");
    scanf("%d",&pr->data);
    int i = 0;
    while(i<n && p!=NULL){
        p = p->next;
		i++;
    }
    if(p!=NULL){
        pr->next = p->next;
        p->next = pr;
    }
    else {
        printf("not exisit!\n");
    }
}


void Change(struct link *head,int n){
    struct link*p = head;
    int i = 0;
    while(i<n && p!=NULL){
        p = p->next;
        i++;
    }
    if(p!=NULL){
        printf("New data:");
        scanf("%d",&p->data);
    }
    else{
        printf("not exisit!\n");
    }
}

int main(){
    struct link*head =NULL;
    int n;
    int n2;
    char c;
    printf("The number of nodes:");
    scanf("%d",&n);
    head = Creat(n);
    Print(head);
    while(1){
        printf("Choose a operation:\n");
        printf("1.Insert\n2.Delete\n3.Change\n4.Exit\n");
        scanf("%c",&c);
        if(c == '1'){
            printf("The number of location:");
            scanf("%d",&n2);
            Insert(head,n2);
            Print(head);
        }
        else if(c == '2'){
            printf("The number of location:");
           scanf("%d",&n2);
           Delete(head,n2);
           Print(head);
        }
        else if(c == '3'){
            printf("The number of location:");
            scanf("%d",&n2);
            Change(head,n2);
            Print(head);
        }
        else if(c == '4'){
            exit(0);
        }
    }
}
