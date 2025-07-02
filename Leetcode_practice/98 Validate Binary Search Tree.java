import javax.swing.tree.TreeNode;

/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
 
class Solution {

    // 檢查二叉樹是否為有效的二叉搜索樹
    boolean isValid(TreeNode root, long min, long max) {

        // 如果節點為空，則返回 true
        if (root == null) return true;

        // 如果節點的值不在允許範圍內，則返回 false
        if (root.val >= max || root.val <= min) return false;

        // 遞歸檢查左子樹和右子樹
        return isValid(root.left, min, root.val) && isValid(root.right, root.val, max);
    }

    // 主函數，檢查整棵樹是否為有效的二叉搜索樹
    public boolean isValidBST(TreeNode root) {
        return isValid(root, Long.MIN_VALUE, Long.MAX_VALUE);
    }
}