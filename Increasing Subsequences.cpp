 Increasing Subsequences.cpp
https://leetcode.com/problems/increasing-subsequences/#/description
class Solution {
public:
    vector<int> tmp;
    set<vector<int>> ans;
    void bt(int n, vector<int> &nums)
    {
        if (n >= nums.size())
            return;

        for (int i = n; i < nums.size(); i++)
        {
            if(tmp.size() == 0 || nums[i] >= tmp.back()){
                tmp.push_back(nums[i]);
                if (tmp.size() >= 2)
                    ans.insert(tmp);
                bt(i+1, nums);
                tmp.pop_back();
            }
        }

    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        bt(0, nums);
        vector<vector<int>> r;
        for(auto &i:ans)
        {
            r.push_back(vector<int>(i.begin(), i.end()));
        }
        return r;
        
    }
};

