Count Numbers with Unique Digits
https://leetcode.com/problems/count-numbers-with-unique-digits/

class Solution {
public:
    int level(int n)
    {
        int i = 9;
        int j = 1;
        while(i >= (9 - n + 2))
        {
            j = j * i;
            i--;
        }
        return j;
    }
    int countNumbersWithUniqueDigits(int n) {
        if (n == 0) return 1;
        if (n == 1) return 10;
        int sum = 0;
        sum = 9 * level(n) + countNumbersWithUniqueDigits(n - 1);
        return sum;
    }
};


