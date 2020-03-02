Ⅰ. 
struct ListNode* rotateRight(struct ListNode* head, int k){
     if(k == 0 || head == NULL)
        return head;
    struct ListNode*tra = head,*H = head;
    int cnt = 1;
    while(tra->next){
        cnt++;
        tra =tra->next;
    }
    tra->next = head;
    k = cnt - k % cnt;
    for(int i = 1 ; i < k; i++ ){
        head = head->next;
    }
        H = head->next;
        head->next = NULL;
        return H;
}
Ⅱ.JAVA
class Solution {
    public ListNode rotateRight(ListNode head, int k) {
            if(head == null ||(head !=null && head.next == null))
                return head;
            ListNode travle = head;
            int count = 1;
            while(travle.next != null){
                count++;
                travle = travle.next;
            }
            travle.next = head;
            ListNode cur = head;
            for(int i = 1;i < count - k%count; i++){
                    cur = cur.next;
            }
            ListNode result = cur.next;
            cur.next = null;
            return result;
    }
}
