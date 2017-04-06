https://leetcode.com/problems/count-primes/#/description
class Solution {
public:
    int countPrimes(int n) {
        if (n <= 1)
            return 0;
        n -= 1;
    	bool prime[n + 1];
    	int cnt = 0;
    	for (int j = 0; j <= n; j++)
    		prime[j] = true;
        int i = 2;
        while(i * i <= n) {
            if (prime[i] == false) {
            	i++;
            	continue;
            }
            for (int j = i + i; j <= n; j += i) {
            	if (prime[j] == true)
            	    cnt++;
            	prime[j] = false;
            }
            i++;
        }
        return n - cnt - 1;
    }
};


