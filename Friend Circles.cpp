Friend Circles
https://leetcode.com/submissions/detail/99138341/
class Solution {
public:
    void traverse(vector<vector<int>>& M, vector<int> &trace, int i, int orig) {
        for (int j = 0; j < M.size(); j++) {
            if (M[i][j] == 1) {
                if (i != j && trace[j] == 0) {
                    trace[j] = 1;
                    traverse(M, trace, j, 0);
                }
            }
        }
    }
    int findCircleNum(vector<vector<int>>& M) {
        vector<int> trace(M.size(), 0);
        int cnt = 0;
        for (int i = 0; i < M.size(); i++) {
            if (trace[i] == 0) {
                trace[i] = 1;
                cnt++;
                for (int j = 0; j < M.size(); j++) {
                    if (i != j && trace[j] == 0 && M[i][j] == 1) {
                        trace[j] = 1;
                        traverse(M, trace, j, i);
                    }
                }
            }
            

        }
        return cnt;
    }
};
