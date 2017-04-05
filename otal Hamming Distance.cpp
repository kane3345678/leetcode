Total Hamming Distance
https://leetcode.com/submissions/detail/99141957/
class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int cnt = 0;
        int n = nums.size();
        for (int i = 0; i < 32; i++) {
            int nums_1 = 0;
            for (int j = 0; j < nums.size(); j++) {
                nums_1 += (nums[j] >> i) & 1;
            }
            cnt += (nums_1 * (n - nums_1));
        }
        return cnt;
    }
};
