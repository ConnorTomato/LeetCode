Ⅰ.C
#include<stdio.h>
#include<stdlib.h>
struct ListNode{
    int Data;
    struct ListNode*next;
};

struct ListNode*Creat(int n){
    struct ListNode*head,*node,*end;
    head = (struct ListNode*)malloc(sizeof(struct ListNode));
    end = head;
    for(int i = 0; i<n; i++)
    {
        node = (struct ListNode*)malloc(sizeof(struct ListNode));
        scanf("%d",&node->Data);
        end->next = node;
        end = node;
    }
    end->next = NULL;
    return head;
}


struct ListNode* reverseList(struct ListNode* head){
    
    struct ListNode * res = NULL, *cur = head;
    while (head != NULL){
        head = head->next;
        cur->next = res;
        res= cur;
        cur = head;

    }
    return res;
}
void Print(struct ListNode*head){
    struct ListNode*p = head;
    p = p->next;
    while(p){
        printf("%d\t",p->Data);
        p = p->next;
    }
}
int main(){
    struct ListNode*head;
    int n;
    int N;
    scanf("%d",&n);
    head = Creat(n);
    Print(head);
    printf("\n");
    head = reverseList(head);
    Print(head);
}
Ⅱ.java迭代
class Solution {
    public ListNode reverseList(ListNode head) {
        ListNode pre = null;
        ListNode cur = head;
        while( cur != null){
            ListNode next = cur.next;
                cur.next = pre;
                pre = cur;
                cur = next;
        }
        return pre;
    }
}
