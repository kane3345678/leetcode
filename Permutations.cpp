Permutations
https://leetcode.com/problems/permutations/
class Solution {
public:
    vector<int> tmp;
    vector<vector<int>> ans;
    vector<int> f;
    void per(int n, vector<int>& nums)
    {
        if (n >= nums.size())
        {
            ans.push_back(tmp);
            return;
        }
        for (int i = 0; i < nums.size(); i++)
        {
            if (f[i] == 0)
            {
                f[i] = 1;
                tmp.push_back(nums[i]);
                per(n + 1, nums);
                tmp.pop_back();
                f[i] = 0;
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        f = vector<int> (nums.size(), 0);
        per(0, nums);
        return ans;
    }
};


