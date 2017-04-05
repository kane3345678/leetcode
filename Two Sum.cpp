Two Sum
https://leetcode.com/problems/two-sum/
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<string, int> hash;
        vector<int> ans;
        for (int i = 0;i< nums.size(); i++)
        {
            int n = target - nums[i];
            string key = to_string(nums[i]);
            if (hash.find(to_string(n)) != hash.end())
            {
                ans.push_back(hash[to_string(n)]);
                ans.push_back(i);
                
                return ans;
            }
            hash[key] = i;
            
        }
        return ans;
    }
};

