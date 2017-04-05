House Robber
https://leetcode.com/problems/house-robber/
class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 0)
            return 0;

        vector<int> stolen(nums.size(), 0);
        stolen[0] = nums[0];
        if (nums.size() == 1)
            return nums[0];
        
        for (int i = 1; i < nums.size(); i++)
        {
            if (i - 2 >= 0) 
                stolen[i] = max(nums[i] + stolen[i - 2], stolen[i-1]);
            else 
                stolen[i] = max(nums[i], nums[i-1]);
        }
        return stolen.back();
    }
};


