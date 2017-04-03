//Serialize and Deserialize BST
https://leetcode.com/submissions/detail/98946346/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    string inorder;
    string postorder;
    void traverse(TreeNode *t) {
        if (t->left != NULL) {
            traverse(t->left);
        }
        inorder += to_string(t->val) +"-";
        if (t->right != NULL)
            traverse(t->right);
        postorder += to_string(t->val) + "-";
        
    }
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (root == NULL)
            return "";
        traverse(root);
        cout<<inorder<<endl;
        cout<<postorder<<endl;
        return inorder + ":" + postorder;
    }
#define char_2_int(x) (x - '0')
#define p post.begin()
#define dump(v) for (auto i : v) cout<<i<<endl
    TreeNode *construct_t(vector<int> post, vector<int> in) {
        if (post.size() == 0)
            return NULL;
        if (post.size() == 1)
            return new TreeNode(post[0]);
        int n = post.size();
        TreeNode *root = new TreeNode(post[n-1]);

        int i = find(in.begin(), in.end(), post[n-1]) - in.begin();
        vector<int> l = vector<int>(in.begin(), in.begin() + i);
        vector<int> r = vector<int>(in.begin()+ i+1, in.end());
        vector<int> l_po = vector<int>(p, p + l.size());
        vector<int> r_po = vector<int>(p + l.size(), p+ l.size() + r.size());
        /*dump(l);
        dump(r);
        dump(l_po);
        dump(r_po);*/
        root->left = construct_t(l_po, l);
        root->right = construct_t(r_po, r);
        return root;
    }
    void create_order(vector<int> &v, string s) {
        string tmp = "";
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '-'){
                v.push_back(stoi(tmp));
                tmp = "";
            }
            else
                tmp += s[i];
        }
    }
    
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int i = data.find(':');
        if (i == string::npos)
            return NULL;

        inorder = data.substr(0, i);
        postorder = data.substr(i + 1);
        vector<int> po;
        vector<int> in;
        create_order(po, postorder);
        create_order(in, inorder);

        TreeNode *root = construct_t(po, in);
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));