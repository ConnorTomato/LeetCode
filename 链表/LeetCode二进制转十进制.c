/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


int getDecimalValue(struct ListNode* head){
    int sum = 0;
    while(head){
    sum = (sum<<1)+head->val;
    /**
      * Eg:1 0 1
      * sum = (0 * 2) + 1;
      * sum = (1 * 2) + 0;
      * sum = (2 * 2) + 1;
      */   
    head = head->next;
    }
    return sum ;
}


int getDecimalValue(struct ListNode* head){
    struct ListNode*p;
    p = head;
    int sum = 0;
    int cnt = 0;
    while(p && p->next)
    {
        p = p->next;
        cnt++;
    }
    p = head;
    while(p)
    {
        sum += (p->val<<cnt);
        p = p->next;
        cnt--;
    }
    return sum;
}