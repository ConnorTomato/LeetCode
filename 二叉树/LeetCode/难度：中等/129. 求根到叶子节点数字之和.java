//1.
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
//2.双栈实现
class Solution {
    public int sumNumbers(TreeNode root) {
        if(root == null)
            return 0;
        int sum = 0;
        Stack<TreeNode> nodes = new Stack<>();
        Stack<Integer> counts = new Stack<>();
        TreeNode current = root;
        nodes.push(current);
        counts.push(0);
        while(!nodes.isEmpty()){
            current = nodes.pop();
            int temp = counts.pop()*10 + current.val;
            if(current.left == null && current.right == null)
                sum += temp;
            if(current.left != null){
                nodes.push(current.left);
                counts.push(temp);
            }
            if(current.right != null){
                nodes.push(current.right);
                counts.push(temp);
            }

        }
        return sum;
    }

}
