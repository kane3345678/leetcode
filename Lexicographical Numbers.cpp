https://leetcode.com/problems/lexicographical-numbers/

class Solution {
public:
    void make_lex(vector<int> &nums, int n, int mul) {
        for (int i = 0; i <= 9; i++) {
            if (mul + i > n)
                return;
            int sum = (mul + i);
            if (sum <= n && sum > 0) {
                nums.push_back(sum);
                make_lex(nums, n, sum*10);
            }
            else if(sum >0)
                nums.push_back(mul + i);
        }
    }
    vector<int> lexicalOrder(int n) {
        vector<int> ans;
        make_lex(ans, n, 0);
        return ans;
    }
};