https://leetcode.com/problems/increasing-triplet-subsequence/#/description
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        if (nums.size() < 3)
            return false;
        bool found = false;
        vector<int> s;
        int i = 1;
        s.push_back(nums[0]);
        while (i < nums.size()) {
            if (nums[i] > s.back()) {
                s.push_back(nums[i]);
            }
            else if(nums[i] < s.back()) {
                for (auto &k : s) 
                    if (k >= nums[i]) {
                        k = nums[i];
                        break;
                    }
            }

            if (s.size() >= 3)
                return true;
            i++;
        }
        return false;
    }
};
