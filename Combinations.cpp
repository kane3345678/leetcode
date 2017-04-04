Combinations
class Solution {
public:
vector<vector<int>> ans;
    void combi(int n, int k, int i, vector<int> v) {
		if (v.size() == k) {
			ans.push_back(v);
			return;
		}
		if (i > n)
			return;
		v.push_back(i);
		combi(n, k, i+1, v);
		v.pop_back();
		combi(n, k, i+1, v);
	}
    vector<vector<int>> combine(int n, int k) {
		vector<int> v;
        combi(n, k, 1, v);
		return ans;
    }
};
