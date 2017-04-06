Coin Change
https://leetcode.com/submissions/detail/99268013/
class Solution {
public:
int coinChange(vector<int>& coins, int amount) {
		int i = 0, j = 0;
		if (!amount) return 0;
		sort(coins.begin(), coins.end());
		vector<vector<int>> a(coins.size(), vector<int>(amount + 1, 0));
		for (j = 0; j <= amount; j++)
		    if (j % coins[0] == 0) a[0][j] = j / coins[0];

		for (i = 1; i < coins.size(); i++) {
			for(j = 1; j <= amount; j++) {
			    if (j >= coins[i]) {
					int k = j - coins[i];
					if (a[i][k] > 0 && a[i-1][j] > 0)
					    a[i][j] = min(a[i][k] + 1, a[i-1][j]);
					else if (a[i][k] > 0 && a[i-1][j] == 0)
						a[i][j] = a[i][k] + 1;
					else if (j % coins[i] == 0)
					    a[i][j] = j / coins[i];
				    else 
					    a[i][j] = a[i-1][j];
				}
				else if (i < coins[i]) {
					a[i][j] = a[i-1][j];
				}
			}
		}
		if (a[coins.size() - 1][amount] == 0)
		    return -1;
		return a[coins.size() - 1][amount];
}
};


