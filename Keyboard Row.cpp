https://leetcode.com/submissions/detail/98918705/
Keyboard Row
class Solution {
public:
	bool check_exist(string s, char c) {
		if (s.find(c) != string::npos)
			return true;
		return false;
	}
    vector<string> findWords(vector<string>& words) {
		vector<string> ans;
        string rows[3] = {"qwertyuiopQWERTYUIOP", "asdfghjklASDFGHJKL", \
							"zxcvbnmZXCVBNM"};
        for (auto &str : words) {
			for (auto k : rows) {
			    bool found = true;
				for (int i = 0; i < str.size(); i++) {
					if (!check_exist(k, str[i])) {
					    found = false;
						break;
					}
				}
				if (found) {
				    ans.push_back(str);
				    break;
				}
			}
        }
        
        return ans;
    }
};