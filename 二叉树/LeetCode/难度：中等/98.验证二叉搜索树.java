   1. 左子树的最大值要小于根节点
   2. 右子树的最小值要大于根节点
   3. 深度遍历的时，左右子树是否符合规则，不符合规则返回False。符合规则，则将左右子树分别返回的最大最小值更新，同时判断与根节点的规则
   4. 将当前子树的最大值、最小值和结果返回。


class Solution {
    public boolean isValidBST(TreeNode root) {
    if (root == null || root.left == null && root.right == null) {
        return true;
    }
    //左子树是否合法
    if (isValidBST(root.left)) {
        if (root.left != null) {
            int max = getMaxOfBST(root.left);//得到左子树中最大的数
            if (root.val <= max) { //相等的情况，代表有重复的数字
                return false;
            }
        }

    } else {
        return false;
    }

    //右子树是否合法
    if (isValidBST(root.right)) {
        if (root.right != null) {
            int min = getMinOfBST(root.right);//得到右子树中最小的数
            if (root.val >= min) { //相等的情况，代表有重复的数字
                return false;
            }
        }

    } else {
        return false;
    }
    return true;
}

private int getMinOfBST(TreeNode root) {
    int min = root.val;
    while (root != null) {
        if (root.val <= min) {
            min = root.val;
        }
        root = root.left;
    }
    return min;
}

private int getMaxOfBST(TreeNode root) {
    int max = root.val;
    while (root != null) {
        if (root.val >= max) {
            max = root.val;
        }
        root = root.right;
    }
    return max;
}
