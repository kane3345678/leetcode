https://leetcode.com/submissions/detail/99028383/
Arranging Coins.cpp
class Solution {
public:
    long sum(int n) {
        if (n == 1)
            return 1;
        return (long(1 + n) * long(n)) / 2;
    }
    int arrangeCoins(int n) {
        if (n == 0)
            return 0;
        if (n <= 2)
            return 1;
        long i = 1, j = n;        
        long mid = 0;
        while (i < j) {
            long mid = (i + j) / 2;
            //cout << mid<<"   "<<sum(mid)<<endl;
            if (sum(mid) > n)
                j = mid ;
            else
                i = mid + 1;
        }
        if (sum(i) == n)
            return i;
        return i - 1;
    }
};
