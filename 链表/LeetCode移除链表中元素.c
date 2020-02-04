

  struct ListNode {
      int val;
      struct ListNode *next;
  };
struct ListNode* removeElements(struct ListNode* head, int val){
    struct ListNode*p ,*pr;
    //创建虚拟头节点
    p = (struct ListNode*)malloc(sizeof(struct ListNode));
    //记录头节点
    pr = p;

    while(head!=NULL)
    {
        if(head->val!=val){
            p->next = head;
            p = p->next;
            head = head->next;
        }
        else{
            head = head->next;
        }

    }
    if(p!=NULL)
        p->next = NULL;
 
    return pr->next;//pr本身数据域为空，指针域指向节点即为第一个数据

}
数据结构中，在单链表的开始结点之前附设一个类型相同的结点，称之为头结点。头结点的数据域可以不存储任何信息，头结点的指针域存储指向开始结点的指针（即第一个元素结点的存储位置）。
作用
1、防止单链表是空的而设的.当链表为空的时候,带头结点的头指针就指向头结点.如果当链表为空的时候,单链表没有带头结点,那么它的头指针就为NULL.
2、是为了方便单链表的特殊操作,插入在表头或者删除第一个结点.这样就保持了单链表操作的统一性!
3、单链表加上头结点之后，无论单链表是否为空，头指针始终指向头结点，因此空表和非空表的处理也统一了，方便了单链表的操作，也减少了程序的复杂性和出现bug的机会。
4、对单链表的多数操作应明确对哪个结点以及该结点的前驱。不带头结点的链表对首元结点、中间结点分别处理等；而带头结点的链表因为有头结点，首元结点、中间结点的操作相同 ,从而减少分支，使算法变得简单 ,流程清晰。对单链表进行插入、删除操作时，如果在首元结点之前插入或删除的是首元结点，不带头结点的单链表需改变头指针的值，在C 算法的函数形参表中头指针一般使用指针的指针；而带头结点的单链表不需改变头指针的值，函数参数表中头结点使用指针变量即可