Number of Segments in a String
https ://leetcode.com/submissions/detail/98822878/
class Solution {
public:
	int countSegments(string s) {
		int i = 0, n = s.size();
		int cnt = 0;
		string tmp;
		while (i < n) {
			if (s[i] != ' ') {
				tmp += s[i];
			}
			else if (s[i] == ' ' && tmp.size() > 0) {
				tmp = "";
				cnt++;
				i++;
				while (s[i] == ' ' && i < n)
					i++;
				continue;
			}
			i++;
		}
		if (tmp.size() > 0)
			cnt++;
		return cnt;
	}
};