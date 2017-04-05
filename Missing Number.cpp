Missing Number
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int of = 0x8fffff;
        int zf = -1;
        for (int i = 0; i < nums.size(); i++)
        {
            if (abs(nums[i]) == nums.size())
                of = nums.size();
            else if (nums[abs(nums[i])] == 0){
                zf = abs(nums[i]);
            }
            else if(nums[i] == 0 && zf==-1){
                zf = -2;
            }
            else if(nums[i] != 0x8fffff){
                nums[abs(nums[i])] = -nums[abs(nums[i])];
            }
        }
        if (of == 0x8fffff)
            return nums.size();
        else if (zf == -1)
            return 0;
 
        for (int i = 1; i < nums.size(); i++)
        {
            if (i == zf)
                continue;
            if (nums[i] >= 0)
                return i;
        }
        return 0;
    }
};


