Binary Tree Level Order Traversal II
https://leetcode.com/problems/binary-tree-level-order-traversal-ii/
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
    vector<vector<int>> ans;
    void dst(TreeNode *t, int n)
    {
        if (t == NULL)
            return;
        if(ans.size() <= n)
            ans.insert(ans.begin(), vector<int>());
            

        ans[ans.size() - n -1].push_back(t->val);
        if (t->left != NULL)
        {
            dst(t->left, n +1);
        }
        if (t->right != NULL)
        {
            dst(t->right, n +1);
        }
    }
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        
        int n = 0;
        if (root == NULL)
            return ans;
        
        dst(root, n);
        return ans;
    }
};

