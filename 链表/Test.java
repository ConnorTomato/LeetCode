/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
思路：
        先遍历链表a，将a链表的所有节点放入一个set中。
        之后再遍历b链表，如果b链表的某个节点出现在set中，那么就找到了第一个相交的节点
public class Solution {
    public ListNode getIntersectionNode(ListNode headA, ListNode headB) {
        Set s = new HashSet();
        ListNode pA = headA;
        ListNode pB = headB;
        while(pA  != null){
            s.add(pA);
            pA = pA.next;
        }
        while(pB != null){
            if(s.contains(pB))
                return pB;
            else
                pB = pB.next;
        }
        return null;
    }
}
