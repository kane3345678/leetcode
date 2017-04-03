https://leetcode.com/submissions/detail/96932617/
class Solution {
public:
	int check_no_dup(string str)
	{
		string tmp;
		for (int i = 0; i < str.size(); i++) {
			if (tmp.find(str[i]) >(tmp.size())) {
				tmp += str[i];
			}
			else {
				return 0;
			}
		}
		return 1;
	}
	int lengthOfLongestSubstring(string s) {
		string sub = "";
		int biggest = 0;
		if (check_no_dup(s)){
			return s.size();
		}
		for (int i = 1; i <= s.size(); i++){
			for (int pos = 0; (pos + i) <= s.size(); pos++) {
				sub = s.substr(pos, i);
				//cout << pos<<","<<i<<endl;
				if (check_no_dup(sub)){

					if (biggest < sub.size())
						biggest = sub.size();
				}
			}
		}
		return biggest;
	}
};


