https://leetcode.com/problems/reconstruct-original-digits-from-english/#/solutions
class Solution {
public:
    string originalDigits(string s) {
		int cnt[10];
		for (int i = 0; i < 10; i++) {
		       cnt[i] = 0;
		}
		string ans = "";
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == 'z') cnt[0]++;
			else if (s[i] == 'o') cnt[1]++;
			else if (s[i] == 'w') cnt[2]++;
			else if (s[i] == 'h') cnt[3]++;
			else if (s[i] == 'u') cnt[4]++;
			else if (s[i] == 'f') cnt[5]++;
			else if (s[i] == 'x') cnt[6]++;
			else if (s[i] == 'v') cnt[7]++;
			else if (s[i] == 'g') cnt[8]++;
			else if (s[i] == 'i') cnt[9]++;
		}
		cnt[5] -= cnt[4];
		cnt[3] -= cnt[8];
		cnt[1] -= (cnt[0] + cnt[2] + cnt[4]);
		cnt[9] -= (cnt[5] + cnt[6] + cnt[8]);
		cnt[7] -= cnt[5];
		for (int i = 0; i < 10; i++) {
			ans += string(cnt[i], 0x30 + i);
		}
		return ans;
	}
};