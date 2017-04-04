Unique Binary Search Trees
https://leetcode.com/problems/unique-binary-search-trees/
class Solution {
public:
    int numTrees(int n) {
        vector<int> f(n + 1);
        f[1] = 1;
        f[0] = 1;
        if(n <= 1)
            return f[n];
        for (int k = 2; k <= n; k++)
        {
            int sum = 0;
            for (int i = 1; i <= k; i++)
            {
                sum += f[k - i] * f[i - 1] ;
            }
            f[k] = sum;
        }
        return f[n];
    }
    
};

