#### [104. 二叉树的最大深度](https://leetcode-cn.com/problems/maximum-depth-of-binary-tree/)

> 执行用时：0 ms, 在所有 Java 提交中击败了100.00%的用户·

```java
class Solution {
    public int maxDepth(TreeNode root) {
        if(root == null){
            return 0;
        }
        return Math.max(maxDepth(root.left),maxDepth(root.right)) + 1;
    }
}




class Solution {
    public int maxDepth(TreeNode root) {
    if(root == null) return 0;
    int leftDepth = maxDepth(root.left);
    int rightDepth = maxDepth(root.right);
    return Math.max(leftDepth,rightDepth)+1;
    }
}
```

