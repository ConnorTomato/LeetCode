#### [剑指 Offer 09. 用两个栈实现队列](https://leetcode-cn.com/problems/yong-liang-ge-zhan-shi-xian-dui-lie-lcof/)

> - Stack 在 JDK 1.0推出，由于历史原因，官方不推荐使用Stack
>
> - Key Point : 
>
>   一个队列具备的两个功能分别由两个栈来完成：栈A实现入队功能，栈B实现出队功能。
>
>   栈的底部对应队列的头部，栈的顶部对应队列的尾部。

```java
class CQueue {
    Deque<Integer> A ;
    Deque<Integer> B;

    public CQueue() {
        A = new LinkedList<Integer>();
        B = new LinkedList<Integer>();
    }
    
    public void appendTail(int value) {
        A.addLast(value);
    }
    
    public int deleteHead() {
        if(!B.isEmpty()){
            return B.removeLast();
        }
        if(A.isEmpty()){
            return -1;
        }
       while(!A.isEmpty()){
           B.addLast(A.removeLast());
       }
       return B.removeLast();
    }
}
```

