Target Sum
https://leetcode.com/problems/target-sum/
class Solution {
public:
    vector<int> ans;
    int sum = 0;
    int f(int S, int n)
    {
        if (n == -1)
        {
            if (S == 0)
            {
                sum++;
                return 1;
            }
            else
                return 0;
        }
        return f(S - ans[n], n - 1) + f(S + ans[n], n - 1);
    }
    int findTargetSumWays(vector<int>& nums, int S) {
        ans = nums;
        cout<<sum;
        return f(S, nums.size() - 1);
    }
};



