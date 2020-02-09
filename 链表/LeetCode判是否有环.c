/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool hasCycle(struct ListNode *head) {
    struct ListNode *pre = head,*cur = head;
    while( cur && cur->next){
        cur = cur->next->next;
        pre = pre->next;
        if(pre == cur )
            return true;
    }
    return false;
}