Permutations II

class Solution {
public:
    vector<vector<int>> ans;
    vector<int> f;
    vector<int> tmp;
    void permu(int n, vector<int> &nums)
    {
        if (n >= nums.size())
        {
            ans.push_back(tmp);
            return;
        }
        vector<int> last;
        for (int i = 0; i < nums.size(); i++)
        {
            
            if (f[i] == 0 && find(last.begin(), last.end(), nums[i]) == last.end())
            {
                f[i] = 1;
                tmp.push_back(nums[i]);
                
                permu(n + 1, nums);
                last.push_back(nums[i]);
                tmp.pop_back();
                f[i] = 0;
            }
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        f = vector<int> (nums.size(), 0);
        permu(0, nums);
        return ans;
    }
};

