Maximum XOR of Two Numbers in an Array
class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int max = 0, mask = 0;
        for(int i = 5; i >= 0; i--){
            mask = mask | (1 << i);
            unordered_set<int> s;
            for(int num : nums){
                s.insert(num & mask);
            }
            int tmp = max | (1 << i);
            for(auto prefix : s){
                if(s.find(tmp ^ prefix) != s.end()) {
                    max = tmp;
                    break;
                }
            }
        }
        return max;
    }
};

