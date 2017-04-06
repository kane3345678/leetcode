https://leetcode.com/submissions/detail/99277636/
class Solution {
public:
    int trailingZeroes(int n) {
    	int ans = 0;
    	int i = 1;
    	while (pow(5, i) <= n) {
    		ans += n / pow(5, i);
    		i++;
    	}
        return ans;
    }
};


