Contains Duplicate II

https://leetcode.com/problems/contains-duplicate-ii/
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        map<string, int> tmp;
        if (nums.size() == 0)
            return false;
        
        for (int i = 0; i < nums.size();i++){
            string x = to_string(nums[i]);
            cout<<tmp[x]<<endl;
            if (tmp[x] == 0) {
                tmp[x] = i+1;
            } 
            else if(i+1 - tmp[x] <= k)
                return true;
            else
                tmp[x] = i + 1;
            
        }
        return false;
    }
};


