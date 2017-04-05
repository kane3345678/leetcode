https://leetcode.com/submissions/detail/99150962/
Subsets
class Solution {
public:
    vector<vector<int>> ans;
    void combi(vector<int> &nums, vector<int> v, int n) {
        if (n == nums.size()) {
            ans.push_back(v);
            return;
        }
        v.push_back(nums[n]);
        combi(nums, v, n + 1);
        v.pop_back();
        combi(nums, v, n + 1);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        if (nums.size() == 0)
            return ans;
        vector<int> v;
        combi(nums, v, 0);
        return ans;
    }
};
