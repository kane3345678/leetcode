Remove Duplicates from Sorted Array   
https://leetcode.com/problems/remove-duplicates-from-sorted-array/#/description
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() == 0)
            return 0;

        vector<int>tmp (abs(nums.back())+1, 0);
        vector<int>neg (abs(nums.front())+1, 0);

        int cnt = 0;
        auto it = nums.begin();
        while(it < nums.end())
        {
            if (*it < 0)
            {
                if (neg[abs(*it)] == 0)
                {
                    neg[abs(*it)] = 1;
                    it++;
                }
                else{
                    nums.erase(it);
                }
            }
            else{
                if (tmp[*it] == 0)
                {
                    tmp[*it] = 1;
                    it++;
                }
                else{
                    nums.erase(it);
                }
            }
            
        }
        return nums.size();
    }
};


