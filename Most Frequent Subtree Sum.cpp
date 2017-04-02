Most Frequent Subtree Sum
https://leetcode.com/submissions/detail/98828296/
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
	unordered_map<int, int> h;
	pair<int, int> ans;
	vector<int> result;
	int post_order(TreeNode *t) {
		int l = 0;
		int r = 0;
		if (t->left != NULL)
			l = post_order(t->left);
		if (t->right != NULL)
			r = post_order(t->right);
		int sum = l + r + t->val;
		h[sum] += 1;
		if (h[sum] > ans.second) {
            result = vector<int> (0);
			ans = make_pair(sum, h[sum]);
			result.push_back(sum);
		}
		else if (h[sum] == ans.second && sum != ans.first) {
		    result.push_back(sum);
		}
		return sum;
	}
	vector<int> findFrequentTreeSum(TreeNode* root) {

		if (root == NULL)
			return result;
        ans = make_pair(0, 0);
		post_order(root);
		if (ans.second == 1) {
		    result = vector<int> (0);
			for (auto i : h)
			result.push_back(i.first);
		}
	
		return result;
	}
};