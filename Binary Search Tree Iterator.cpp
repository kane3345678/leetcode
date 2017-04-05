Binary Search Tree Iterator
https://leetcode.com/problems/binary-search-tree-iterator/#/description
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
public:
    vector<TreeNode *> v;
    TreeNode *it;
    void dst(TreeNode *t) {
        if (t == NULL)
            return;
        v.push_back(t);
        if (t->left != NULL)
            dst(t->left);
    }
    BSTIterator(TreeNode *root) {
        dst(root);
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        if (v.size() == 0)
            return false;
        else
            return true;
    }

    /** @return the next smallest number */
    int next() {
        if (!hasNext())
            return 0;
        it = v.back();
        v.pop_back();
        if (it->right != NULL)
            dst(it->right);
        
        return it->val;
    }
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */
