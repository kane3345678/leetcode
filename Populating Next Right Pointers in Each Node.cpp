Populating Next Right Pointers in Each Node
Populating Next Right Pointers in Each Node

/**
* Definition for binary tree with next pointer.
* struct TreeLinkNode {
*  int val;
*  TreeLinkNode *left, *right, *next;
*  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
* };
*/
class Solution {
public:
	vector<vector<TreeLinkNode*>> ans;
	void dst(TreeLinkNode *n, int l){
		vector<TreeLinkNode*> b;
		b.push_back(n);

		if (ans.size() < l + 1)
			ans.push_back(b);
		else
			ans[l].push_back(n);

		if (n->left != NULL) {

			dst(n->left, l + 1);
		}

		if (n->right != NULL){
			dst(n->right, l + 1);
		}
	}
	void connect(TreeLinkNode *root) {
		if (root == NULL)
			return;
		dst(root, 0);
		for (int i = 0; i < ans.size(); i++){
			vector<TreeLinkNode*> t = ans[i];
			for (int j = 0; j < t.size() - 1; j++){
				t[j]->next = t[j + 1];
			}
		}
	}
};


