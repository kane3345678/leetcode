https://leetcode.com/problems/rotate-array/
Rotate Array
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if (nums.size() <= 1 || k == 0 || nums.size() == k)
            return;

        k = k % nums.size();
        int x = nums.size() - k;
        int y = 0;
        vector<int> tmp;
        for (int i = 0; i < x; i++)
        {
           tmp.push_back(nums[0]);
           nums.erase(nums.begin());
        }
        
        for (int i = 0; i < tmp.size(); i++)
        {
           nums.push_back(tmp[i]);
        }
    }
};


