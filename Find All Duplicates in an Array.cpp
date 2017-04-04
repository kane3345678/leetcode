https://leetcode.com/problems/find-all-duplicates-in-an-array/
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        if (nums.size() == 0)
            return {};
        sort(nums.begin(), nums.end());
        vector<int> ans;
        auto i = nums.begin();
        auto j = nums.begin() + 1;
        while(j != nums.end())
        {
            if (*i != *j)
            {
                i++;
                j++;
            }
            else
            {
                ans.push_back(*i);
                while(*i == *j)
                {
                    nums.erase(j);
                    if (j == nums.end())
                        break;
                }
                
            }
        }
        return ans;
    }
};
