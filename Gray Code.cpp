https://leetcode.com/submissions/detail/98847509/
Gray Code
class Solution {
public:
    vector<int> grayCode(int n) {
        if (n == 0)
            return vector<int> ({0});
		vector<int> ans({0, 1});
		for (int k = 2; k <= n; k++) {

			vector<int> tmp = ans;
			for (int i = tmp.size() - 1; i >= 0; i--) {
				ans.push_back(tmp[i] + pow(2, k-1));
			}
		}
		return ans;
    }
};