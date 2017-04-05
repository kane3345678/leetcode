Longest Palindrome
https://leetcode.com/problems/longest-palindrome/#/solutions
class Solution {
public:
    
    int longestPalindrome(string s) {
    // find the number of distinct nubmer.
        unordered_map<char, int> h;
        for (int i = 0; i < s.size(); i++)
        {
            if (h.find(s[i]) == h.end())
                h[s[i]] = 1;
            else
                h.erase(s[i]);
        }
        if (h.size() == 0)
            return s.size();
        return s.size() - h.size() + 1;
    }
};

