3Sum
  class Solution {
public:
    int len;
    vector<vector<int>> ans;
    vector<int> d;
    int compare( vector<int> v2)
    {
        vector<int> v3;
        for (int i = 0; i< ans.size(); i++) 
        {
            vector<int> v1 = ans[i];
            if (equal(v1.begin(), v1.end(), v2.begin()))
                return -1;
        }
        return 0;
    }
    void combi(int n, vector<int> sol)
    {
        
        if (sol.size() == 3){
            int sum =0;
            for (int i = 0; i < sol.size(); i++)
            {
                sum += sol[i];
            }
            if (sum == 0)
                ans.push_back(sol);
            return;
        }
        if (sol.size() > 3)
            return;
        if (n >= d.size())
            return;
 
        sol.push_back(d[n]);
        combi(n + 1, sol);
        sol.pop_back();
        combi(n + 1, sol);
    }

    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        d = nums;
        vector<int> sol;
        combi(0, sol);
        return ans;
        
    }
};
