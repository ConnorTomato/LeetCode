#### [141. 环形链表](https://leetcode-cn.com/problems/linked-list-cycle/)

> - 执行用时：0 ms, 在所有 Java 提交中击败了100.00%的用户

```java
public class Solution {
    public boolean hasCycle(ListNode head) {
        if(head == null || head.next == null){
            return false;
        }
        ListNode fast = head, slow = head;
        while(fast != null && fast.next != null){
            slow = slow.next;
            fast = fast.next.next;
            if(fast == slow){
                return true;
            }
        }
        return false;
    }
}
```

