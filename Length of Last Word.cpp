Length of Last Word
https://leetcode.com/problems/length-of-last-word/#/description
class Solution {
    public:
    int lengthOfLastWord(string s) {
    	string ans = "";
    	while (s.size() > 0) {
    		auto p = s.find(' ');
    		if (p == string::npos) {
                ans = s;
    			break;
    		}
    		if (p != 0)
    		    ans = s.substr(0, p);
    		s = s.substr(p + 1);
    	}
    	return ans.size();
    }
};


