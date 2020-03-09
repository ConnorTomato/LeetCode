### 解题思路
![批注 2020-02-08 125446.png](https://pic.leetcode-cn.com/e3729af0b46b2526d82d95043acc5459acdc46e0c8393c88525fafeb95935217-%E6%89%B9%E6%B3%A8%202020-02-08%20125446.png)
双指针：
    快指针一次走两个节点，慢指针一次走一个节点。
    当快指针为NULL时，慢指针恰好在中点（奇数）or中点偏右（偶数）
### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* middleNode(struct ListNode* head){
    struct ListNode*pre = head,*cur=head;
    while(cur && cur->next)
    {
        cur = cur->next->next;;
        pre = pre->next;
    }
    return pre;
}
