Different Ways to Add Parentheses
https ://leetcode.com/submissions/detail/98902695/
#define chk_digit(c) (c >= 0x30 && c <= 0x39)
class Solution {
public:
	vector<int> diffWaysToCompute(string input) {
		vector<int> ans;
		for (int i = 0; i < input.size(); i++) {
			if (!chk_digit(input[i])) {

				for (auto k : diffWaysToCompute(input.substr(0, i))) {
					for (auto g : diffWaysToCompute(input.substr(i + 1))) {
						//cout<<k<<input[i]<<g<<endl;

						if (input[i] == '+') ans.push_back(k + g);
						else if (input[i] == '*') ans.push_back(k * g);
						else if (input[i] == '-') ans.push_back(k - g);
					}
				}
			}
		}
		if (ans.size() == 0)
			return vector<int>(1, stoi(input));
		else
			return ans;
	}
};