Happy Number
https://leetcode.com/problems/happy-number/
class Solution {
public:
    bool isHappy(int n) {
        unordered_map<int, int> h;
        while (1){
            int z = log(n) + 1;
            int digi = 0;
            int sqre = 0;
            for (int i = 0 ;i < z; i++)
            {
                digi = n % 10;
                sqre += digi *digi;
                n = n/10;
            }
            if (h.find(sqre) != h.end())
                return false;
            else if (sqre == 1)
                return true;
            
            h[sqre] = n;
            n = sqre;
        }
    }
};

