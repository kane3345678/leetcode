Combination Sum IV
https://leetcode.com/submissions/detail/98948130/
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target + 1, 0);
        dp[0] = 1;
        for (int i = 1; i <= target; i++) {
            for (auto j : nums) {
                if (i >= j)
                    dp[i] += dp[i - j];
            }
        }
        return dp[target];
    }
};