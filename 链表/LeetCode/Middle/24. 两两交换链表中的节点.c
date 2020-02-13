递归：
1.递归终止条件：剩余 1 or 0 个节点时结束.
2.递归返回值：已经交换好的节点段
3.本级递归任务：交换两节点



/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* swapPairs(struct ListNode* head){
    //递归结束条件
    if(head ==NULL || head->next == NULL)
        return head;

    //假设链表1->2->3->4;
    //tmp 先保存节点 2
    struct ListNode * tmp = head->next;
    //继续递归，处理3->4
    //当递归结束返回后，就变成4->3
    //于是head节点就指向了4，变成1->4->3
    head->next = swapPairs(tmp->next);
    //将2->1
    tmp->next = head;
    return tmp;

}
