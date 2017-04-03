Pow(x, n)
https://leetcode.com/problems/powx-n/

class Solution {
public:
    double myPow(double x, int n) {
        double y;
        if (x > 0 && x < 1 && n > 64)
        {
            return 0;
        }
        int m = abs(n);
        
        if (m == 1){
            return (n>0)?x:1/x;
        }
        if (m == 0)
            return 1;

        if (m % 2 == 1)
            x = myPow(x, m/2) * myPow(x, m/2) * x;
        else
            x = myPow(x, m/2) * myPow(x, m/2);
        if (n < 0)
            return 1 / x;
        else
            return x;
    }
};

