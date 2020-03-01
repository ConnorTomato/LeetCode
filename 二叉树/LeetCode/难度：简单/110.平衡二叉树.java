class Solution {
    public boolean isBalanced(TreeNode root) {
        if (root == null) {
            return true;
        }
        //递归计算每个节点的左右子树高度
        if(!isBalanced(root.left)) return false;
        if(!isBalanced(root.right)) return false;

        int leftH = dfs(root.left) + 1;     //计算左子树高度
        int rightH = dfs(root.right) + 1;   //计算右子树高度
        if (Math.abs(leftH - rightH) > 1) {
            return false;
        }
        return true;
    }

    /**
     *   算出每个节点的子树高度
     */
    private int dfs(TreeNode x) {
        if (x == null) {
            return 0;
        }
        if (x.left == null && x.right == null) {
            return 1;
        }
        int leftH = dfs(x.left) + 1;
        int rightH = dfs(x.right) + 1;
        return Math.max(leftH, rightH);
    }
}
Ⅱ.
    class Solution {
    public boolean isBalanced(TreeNode root) {
        return treeHeight(root) >= 0;
    }
    public int treeHeight(TreeNode root){
        if(root == null) 
            return 0;
        int leftHeight = treeHeight(root.left);
        int rightHeight = treeHeight(root.right);
        if(leftHeight >= 0 && rightHeight >= 0 &&Math.abs(leftHeight - rightHeight) <=1)
            return Math.max(leftHeight,rightHeight) + 1;
        else
            return -1;        
    }
}
Ⅲ.递归
class Solution {
    public boolean isBalanced(TreeNode root) {
            if( root == null )
                return true;
            int leftH = treeH(root.left);
            int rightH = treeH(root.right);
            if(Math.abs(leftH - rightH) > 1)
                return false;
            return isBalanced(root.left) && isBalanced(root.right);
            
    }

    private int treeH(TreeNode root){
        if(root == null)
            return 0;
        int leftH = treeH(root.left) ;
        int rightH = treeH(root.right);
        return Math.max(leftH,rightH) + 1;
    }
}
