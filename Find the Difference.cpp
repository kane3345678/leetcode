https://leetcode.com/submissions/detail/98919621/
Find the Difference
class Solution {
public:
    unordered_map <char, int> h;
    char findTheDifference(string s, string t) {
        for (int i = 0; i < s.size(); i++)
			h[s[i]] += 1;
		for (int i = 0; i < t.size(); i++) {
			h[t[i]] -= 1;
			if (h[t[i]] < 0)
			    return t[i];
		}

		return 'n';
    }
};