/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


bool isPalindrome(struct ListNode* head){
    struct ListNode*slow = head,*fast = head;
    //找出链表中点
    while( fast && fast->next)
    {
        fast = fast->next->next;
        slow = slow->next;
    }


    struct ListNode*pre = NULL;
    struct ListNode*cur;

    //反转后半部分
    while(slow)
    {
        cur = slow->next;
        slow->next = pre;
        pre = slow;
        slow = cur;
    }


    //比较val
    while(head && pre)
    {
        if(head->val != pre->val)
            return false;
        head = head->next;
        pre = pre->next;
    }
    return true;
}
