Valid Perfect Square
https://leetcode.com/problems/valid-perfect-square/
class Solution {
public:
    bool isPerfectSquare(int num) {
        int i = 0;
        int j = num;
        int mid;
        int sqre;
        while (i<j)
        {
            
            mid = (i + j);
            sqre = mid * mid;
            if (sqre > num)
                j = mid - 1;
            else if (sqre < num)
                i = mid + 1;
            else
                return true;
        }
        return false;
    }
};

