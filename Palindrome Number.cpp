Palindrome Number.cpp
https://leetcode.com/problems/palindrome-number/#/description
space O(n)
class Solution {
public:
    bool isPalindrome(int x) {
        vector<int> stack({x % 10});
        x = x / 10;
        while(x > 0) {
            int tmp = x % 10;
            if (stack.size() > 0 && tmp == stack.front())
                stack.erase(stack.begin());
            else 
                stack.push_back(tmp);
            x = x / 10;
        }
        if (stack.size() <= 1)
            return true;
        else
            return false;
    }
};

space O(1)
class Solution {
public:
    bool isPalindrome(int x) {
        string a = to_string(x);
        int i = 0, j = 0;
        if (a.size() % 2 == 0) {
            j = a.size() / 2;
            i = j - 1;
        }
        else {
            j = a.size() / 2 + 1;
            i = j - 2;
        }
        while (i >= 0) {
            if (a[i] != a[j])
                return false;
            i--;
            j++;
        }
        return true;
    }
};
