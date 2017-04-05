Word Pattern
https://leetcode.com/submissions/detail/99174738/
class Solution {
public:
    bool wordPattern(string pattern, string str) {
    	vector<string> s;
    	string tmp;
    	istringstream st(str);
    	while(getline(st, tmp, ' ')) {
    		s.push_back(tmp);
    	}
    	if (s.size() != pattern.size())
    	    return false;
        s.insert(s.begin(), "x");
    	pattern = " " + pattern;
    	map<char, int> p;
	    map<string, int> stack;
    	for (int i = 1; i < pattern.size(); i++) {
            if (p[pattern[i]] != stack[s[i]])
	            return false;
		    p[pattern[i]] = stack[s[i]] = i;
    	}
    	return true;
    }
};



