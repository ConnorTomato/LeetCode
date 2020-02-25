class Solution {
    public int sumNumbers(TreeNode root) {
        if(root == null)
            return 0;
        return hasSum(root,0);
    }
    public int hasSum(TreeNode root, int count){
        int sum = 0;
        if(root.left == null && root.right == null)
            sum += count*10 + root.val;
        if(root.left != null)
            sum +=hasSum(root.left,count*10+root.val);
        if(root.right != null)
            sum += hasSum(root.right,count*10+root.val);
        return sum;
    }
}
