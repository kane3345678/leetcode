Binary Watch
https ://leetcode.com/problems/binary-watch/#/description
class Solution {
public:
	vector<vector<int>> bits_arr;
	void collect_bits(int num) {
		bits_arr[0].push_back(0);
		int c[60];
		c[0] = 0;
		c[1] = 1;
		c[2] = 1;
		bits_arr[1].push_back(1);
		bits_arr[1].push_back(2);
		for (int i = 3; i <= 59; i++) {
			int tmp = i - pow(2, int(log2(i)));
			if (tmp == 0)
				c[i] = 1;
			else
				c[i] = c[tmp] + 1;
			//cout<<tmp<<"   "<<c[i]<<"   "<<i<<endl;
			bits_arr[c[i]].push_back(i);
		}
	}
	vector<string> readBinaryWatch(int num) {
		bits_arr = vector<vector<int>>(6, vector<int>(0));
		vector<string> ans;
		collect_bits(num);
		string hour = "", min = "";

		for (int i = 0; i <= 3; i++) {
			if (num - i >= 6 || num < i)
				continue;
			for (int j = 0; j < bits_arr[i].size(); j++) {
				for (int k = 0; k < bits_arr[num - i].size(); k++) {
					hour = "0";
					if (bits_arr[i][j] <= 11) {
						hour = to_string(bits_arr[i][j]);
						min = to_string(bits_arr[num - i][k]);
						min = string(2 - min.size(), '0') + min;
						ans.push_back(hour + ":" + min);
					}
				}
			}
		}
		return ans;
	}
};