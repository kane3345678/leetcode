Counting Bits

class Solution {
public:
    vector<int> countBits(int num) {
        if (num == 0)
            return vector<int>({0});
        vector<int> ans(num+1, 0);
        ans[0] = 0;
        int i = 1;
        while (i <= num){
            int x = i - pow(2, int(log(i)/ log(2)));
            ans[i] = 1 + ans[x];
            i++;
        }
        return ans;
    }
};

