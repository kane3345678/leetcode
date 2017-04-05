Best Time to Buy and Sell Stock
https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int i = 0, j = 1, m = 0;
        
        while(j < n)
        {
            if(prices[j] > prices[i])
                m = max(m, prices[j] - prices[i]);
            else
               i = j;
            j++;
        }
        return m;
    }
};


