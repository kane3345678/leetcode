https://leetcode.com/problems/next-permutation/#/description

class Solution {
public:
    void swap(vector<int> &nums, int i,int id)
    {
        nums[i] = nums[i] ^ nums[id];
        nums[id] = nums[i] ^ nums[id];
        nums[i] = nums[i] ^ nums[id];
    }
    void nextPermutation(vector<int>& nums) {
        int i = nums.size() - 2;
        int j = 0;
        if (i == -1){
            return;
        } else if (i == 0){
            nums[0] = nums[0] ^ nums[1];
            nums[1] = nums[0] ^ nums[1];
            nums[0] = nums[0] ^ nums[1];
            return;
        }
        while(i >= 0)
        {
            if (nums[i] < nums[i + 1]) {
                break;
            }
            i--;
        }
        if (i == -1)
        {
            sort(nums.begin(), nums.end());
            return;
        }
        cout << i<<endl;
        j = i + 1;
        int smallest = nums[j];
        int id = j;
        while (j < nums.size()) {
            if (nums[j] > nums[i] && smallest > nums[j] ) {
                smallest = nums[j];
                id = j;
            }
            j++;
        }
        cout << id<<endl;
        swap(nums, i, id);
            
        sort(nums.begin() + i + 1, nums.end());
    }
};


