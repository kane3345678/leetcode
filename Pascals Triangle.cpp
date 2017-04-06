Pascal's Triangle
https://leetcode.com/submissions/detail/99272998/
class Solution {
public:
vector<vector<int>> generate(int numRows) {
	vector<vector<int>> ans;
	for (int i = 0; i < numRows; i++) {
		vector<int> v;
		for (int j = 0; j < i + 1; j++) {
			if (j != 0 && j!=i)
        v.push_back(ans[i-1][j-1]+ans[i-1][j]);	
			else {
        v.push_back(1);		
			}
		}
		ans.push_back(v);
	}
	return ans;
}
};

