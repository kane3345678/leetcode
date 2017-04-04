Path Sum

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
    bool found;
    void dst(TreeNode *t, int sum) {
        if (sum - t->val == 0) {
            if (t->left == NULL && t->right == NULL) {
                found = true;
                return;
            }
        }
        if (t->left != NULL)
            dst(t->left, sum - t->val);
        if (t->right != NULL)
            dst(t->right, sum - t->val);
        
    }
    bool hasPathSum(TreeNode* root, int sum) {
        found = false;
        if (root != NULL)
            dst(root, sum);
        return found;
    }
};

