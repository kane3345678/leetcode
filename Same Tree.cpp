Same Tree
https://leetcode.com/problems/same-tree/
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
    int ans = 1;
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (q == NULL && p == NULL)
            return true;
        else if(p != NULL && q!=NULL){
            if (q->val != p->val)
                ans &= 0;
            
            if (p->left != NULL && q->left!= NULL)
                isSameTree(p->left, q->left);
            else if(p->left != NULL && q->left == NULL)
                ans &= 0;
            else if(p->left == NULL && q->left != NULL)
                ans &= 0;
            
            if (p->right != NULL && q->right!= NULL)
                isSameTree(q->right, p->right);
            else if(p->right != NULL && q->right == NULL)
                ans &= 0;
            else if(p->right == NULL && q->right != NULL)
                ans &= 0;
    
            if (ans == 0)   
                return false;
            else
                return true;
        }
        return false;
    }
};


