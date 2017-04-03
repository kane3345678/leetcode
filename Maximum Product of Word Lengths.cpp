https://leetcode.com/submissions/detail/98933879/
Maximum Product of Word Lengths
class Solution {
public:
#define offset(c) (c - 'a')
    int convert_bit (string a) {
		int bits = 0;
		for (int i = 0; i < a.size(); i++) {
			bits |= 1 << offset(a[i]);
		}
		return bits;
	}

    int maxProduct(vector<string>& words) {
		vector<int> arr;
		int ans = 0;
		for (auto &s : words)
			arr.push_back(convert_bit(s));
		for (int i = 0; i < arr.size(); i++) {
			for (int j = i + 1; j < arr.size(); j++) {
				if ((arr[i] & arr[j]) == 0) {
				    int mul = (words[i].size() * words[j].size());
					ans = max(ans, mul);
				}
			}
		}
		return ans;
    }
};