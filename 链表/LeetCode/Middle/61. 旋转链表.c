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