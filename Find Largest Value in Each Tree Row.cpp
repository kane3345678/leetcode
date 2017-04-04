
Find Largest Value in Each Tree Row
https://leetcode.com/problems/find-largest-value-in-each-tree-row/
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
    void dp(TreeNode* t1, vector<int> &kkk, int n)
    {
        if (kkk.size() < (n + 1)){
            kkk.push_back(t1->val);
        }
        else
            kkk[n] = max(kkk[n], t1->val);
         cout<<kkk.size()<<endl;
        if (t1->left != NULL)
            dp(t1->left, kkk, n+1);
        if (t1->right != NULL)
            dp(t1->right, kkk, n+1);
            
    }
    vector<int> largestValues(TreeNode* root) {
        vector<int> kkk;

        if (root == NULL)
            return kkk;
        dp(root, kkk, 0);
        
        for (auto &i : kkk)
          {
                  cout<<i<<", ";
          }

        return kkk;
    }
};

