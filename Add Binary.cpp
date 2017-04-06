Add Binary
https://leetcode.com/problems/add-binary/#/description
class Solution {
public:
    #define c2int(c) (c - 0x30)
    #define c_add(c1, c2) c2int(c1) + c2int(c2)
    string addBinary(string a, string b) {
    	string ans = "";
        if (a.size() < b.size())        
    	    swap(a, b);
        int i = a.size() - 1, j = b.size() - 1;
        int carry = 0;
        while (i >= 0) {
            int sum = 0;
            if (j < 0)
                sum = c_add(a[i], '0') + carry;
            else
                sum = c_add(a[i], b[j]) + carry;
        	if (sum >= 2) {
        		sum &= 1;
        		ans = to_string(sum) + ans;
        		carry = 1;		
        	}
        	else {
        		ans = to_string(sum) + ans;
        		carry = 0;
        	}
        	i--; j--;
        }
        if (carry > 0)
        	ans = "1" + ans;
        return ans;
    }
};


