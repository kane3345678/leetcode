Random Pick Index
class Solution {
public:
    map<int, vector<int>> tbl;
    Solution(vector<int> nums) {
        int cnt = 0;
        for (auto i : nums) {
            tbl[i].push_back(cnt);
            cnt++;
        }
    }
    
    int pick(int target) {
        int n = tbl[target].size();
        if (n == 1)
            return tbl[target][0];
        else {
            int random = rand() % n;
            return tbl[target][random];
        }
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * int param_1 = obj.pick(target);
 */