#### [103. 二叉树的锯齿形层序遍历](https://leetcode-cn.com/problems/binary-tree-zigzag-level-order-traversal/)

> - 执行用时：1 ms, 在所有 Java 提交中击败了98.42%的用户

```java
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    public List<List<Integer>> zigzagLevelOrder(TreeNode root) {
        if(root == null){
            return Collections.emptyList();
        }
        List<List<Integer>> res = new LinkedList<List<Integer>>();
        Deque<TreeNode> queue = new ArrayDeque<>();
        queue.offer(root);
        int depth = 0;
        while(!queue.isEmpty()){
            int size = queue.size();
            LinkedList<Integer> temp = new LinkedList<Integer>();
            for(int i = 0; i < size; i++){
                TreeNode node = queue.poll();
                if((depth & 1) == 1){
                    temp.addFirst(node.val);
                }else{
                    temp.add(node.val);
                }
                if(node.left != null){
                    queue.offer(node.left);
                }
                if(node.right != null){
                    queue.offer(node.right);
                }
            }
            depth++;
            res.add(temp);
        }
        return res;
    }
}
```

