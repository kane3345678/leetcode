Construct Binary Tree from Inorder and Postorder Traversal
https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/#/solutions
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
    void con_tree(vector<int> buf, vector<int> &post, TreeNode *&parent, int f)
    {
        int  m = 0, r = 0;
        
        if (buf.size() == 1){
            parent = new TreeNode(buf[0]);
            return;
        }
        if(f != -1){
            parent = new TreeNode(buf[f]);
            m = f;
        }
        else {
            m = find(buf.begin(), buf.end(), post.back()) - buf.begin();
            parent = new TreeNode(buf[m]);
        }
        vector<int> po;
        vector<int> in;
        if (m > 0)
        {
            in = vector<int>(buf.begin(), buf.begin() + m);
            po = vector<int>(post.begin(), post.begin()+m);

            con_tree(in, po, parent->left, -1);
        }
        if (m < buf.size() - 1)
        {
            in = vector<int>(buf.begin() + m + 1, buf.end());
            po = vector<int>(post.end() -in.size()-1, post.end() - 1);
            con_tree(in, po, parent->right, -1);
        }

    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if (inorder.size() == 0)
            return NULL;
        int index = find(inorder.begin(), inorder.end(), postorder.back()) - inorder.begin();
        TreeNode *root ;
        con_tree(inorder, postorder, root, index);
        return root;
    }
};

