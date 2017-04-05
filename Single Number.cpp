Single Number
https://leetcode.com/problems/single-number/
class Solution {
public:
    unordered_map<int, int> hash;
    int singleNumber(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i ++)
        {
            int k = nums[i];
            if (hash.find(k) != hash.end() )
                hash.erase(k);
            else
                hash[k] = i;
        }
        //cout<<hash.begin()->first;
        return hash.begin()->first;
        
    }
};



