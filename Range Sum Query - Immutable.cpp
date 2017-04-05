Range Sum Query - Immutable
https://leetcode.com/problems/range-sum-query-immutable/
class NumArray {
public:
    vector<int> ans;
    NumArray(vector<int> nums) {
        if (nums.size() == 0)
            return;
        ans = vector<int>(nums.size());
        ans[0] = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            ans[i] = ans[i-1] + nums[i];
        }
    }
    
    int sumRange(int i, int j) {
        int sum = 0;
        if (ans.size() == 0)
            return 0;
        if (j == 0)
            return ans[0];
        if (i == 0)
            return ans[j];

        sum = ans[j] - ans[i-1];
        return sum;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * int param_1 = obj.sumRange(i,j);
 */


