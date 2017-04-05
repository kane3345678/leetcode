Find the Duplicate Number
https://leetcode.com/problems/find-the-duplicate-number/#/description
class Solution {
public:
    int cnt_bigger(int x, vector<int> &nums)
    {
        int cnt = 0;
        for(int i = 0; i < nums.size();i++)
        {
            if (nums[i] >= x)
                cnt++;
        }
        return cnt;
    }
    int findDuplicate(vector<int>& nums) {
            int n = nums.size() - 1;
            int i = 1, j = n;
            while(j - i > 1)
            {
                int mid = (i + j) /2;
                int cnt = 0;
                if (cnt_bigger(mid, nums) > (n - mid + 1))
                {
                    i = mid;
                }
                else {
                    j = mid;
                }
            }
            if (cnt_bigger(j, nums) > (n - j + 1))
                return j;
            return i;
    }
};


