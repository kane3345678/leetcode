Maximum Depth of Binary Tree
https://leetcode.com/problems/maximum-depth-of-binary-tree/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int n = 0;
    void dst(TreeNode* nd, int level)
    {
        if (nd == NULL)
            return;
        n = max(level, n);
        if (nd->left != NULL)
            dst(nd->left, level + 1);
        if (nd->right != NULL)
            dst(nd->right, level + 1);
    }
    int maxDepth(TreeNode* root) {
        if (root == NULL)
            return 0;
        n++;
        dst(root, 1);
        return n;
    }
};


