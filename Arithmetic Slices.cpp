Arithmetic Slices
https://leetcode.com/problems/arithmetic-slices/
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int n = A.size();
        //vector<vector<int>> ans(n, vector<int>(n , 0));
        vector<int> ans(n, 0);
        int cnt =0;
        if (n < 3)
            return 0;
        for (int i = n - 1; i >= 0; i--){
            ans[i] = 0;
            for (int j = i+1; j < n; j++){
                if (j - i == 1)
                    ans[j] = A[i] - A[j];
                else if(j - i >= 2 && (ans[j] == ans[j-1]))
                {
                    ans[j] = ans[j-1];
                    cnt++;
                }
                else
                    break;
            }
        }
        return cnt;
    }
};


