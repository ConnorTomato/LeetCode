Ⅰ.迭代
class Solution {
    public List<Integer> inorderTraversal(TreeNode root) {
        List<Integer> result = new LinkedList<>();
        if(root == null)  
            return result;

        Stack<TreeNode> stack = new Stack<>();
        TreeNode node = root;

        while(!stack.isEmpty() || node != null){
            while(node != null){
                stack.push(node);
                node = node.left;
            }
            node = stack.pop();
            result.add(node.val);
            node = node.right;
        }
        return result;
    }
}

Ⅱ.递归
class Solution {
    public List<Integer> inorderTraversal(TreeNode root) {
        List<Integer> result = new LinkedList<>();
        dfs(result,root);
        return result;
    }
    public void dfs(List<Integer> result, TreeNode root){
        if(root == null)
            return;
        dfs(result,root.left);
        result.add(root.val);
        dfs(result,root.right);
        
    }
}
