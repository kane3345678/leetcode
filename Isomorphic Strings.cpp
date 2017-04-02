https://leetcode.com/submissions/detail/98824506/
Isomorphic Strings
class Solution {
public:
	bool isIsomorphic(string s, string t) {
		string a = "", b = "";
		int n = s.size(), i = 0;
		while (i < n) {
			auto pos1 = a.rfind(s[i]);
			auto pos2 = b.rfind(t[i]);
			a += s[i];
			b += t[i];
			if (pos1 != pos2)
				return false;
			i++;
		}
		return true;
	}
};

