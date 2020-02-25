class Solution {
    public boolean hasPathSum(TreeNode root, int sum) {
        if(root == null)
            return false;//递归结束条件
        sum -= root.val;//每一次减去当前节点值
        if(root.left == null && root.right == null && sum == 0)
            return true;
        return hasPathSum(root.left,sum) || hasPathSum(root.right,sum);
        
    }
}
