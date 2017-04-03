First Unique Character in a String
https://leetcode.com/submissions/detail/98921963/
class Solution {
public:
    map<char, int> h;
    int firstUniqChar(string s) {
		int cnt = 0;
		if (s.size() == 0) return -1;
        for (int i = 0; i < s.size(); i++) {
            if (h[s[i]] == 0)
			    h[s[i]] = i + 1;
			else if(h[s[i]] > 0)
			    h[s[i]] = 0-h[s[i]];
        }
        int m = s.size();
		for (auto i : h) {
			if (i.second > 0)
			    m =min(m, i.second - 1);
		}
		if (m == s.size())
		    return -1;
		return m;
    }
};