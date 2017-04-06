Valid Anagram
https://leetcode.com/problems/valid-anagram/#/description
class Solution {
public:
    bool isAnagram(string s, string t) {
	    if (s.size() != t.size())
		    return false;
		unordered_map<char, int> s1;
		unordered_map<char, int> t1;
		for (int i = 0; i < s.size(); i++) {
			s1[s[i]] += 1;
			t1[t[i]] += 1;
		}
		for (auto &i : s1) {
			if (i.second != t1[i.first])
				return false;
		}
		return true;
    }
};


