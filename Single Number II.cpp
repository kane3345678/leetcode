https://leetcode.com/problems/single-number-ii/#/solutions
Single Number II
class Solution {
public:
	int singleNumber(vector<int>& nums) {
		int ans = 0;
		for (int i = 0; i < 32; i++) {
			int sum = 0;
			for (auto k : nums) {
				sum += ((k >> i) & 1);
				sum %= 3;
			}
			if (sum > 0)
				ans += (sum << i);
		}
		return ans;
	}
};