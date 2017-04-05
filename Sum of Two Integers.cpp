Sum of Two Integers.cpp
class Solution {
public:
    int getSum(int a, int b) {
        int carry = 0;
        int sum = 0;
        for (int i = 0; i < 32; i++) {
            int bit_a = (a & (1 << i));
            int bit_b = (b & (1 << i));
            //cout<<"car = "<<carry<<endl;

            sum |= (bit_a ^ bit_b ^ (carry << i));
            //cout<<"sum="<<sum<<endl;
            if ((bit_a & bit_b) > 0)
                carry = 1;
            else if ((bit_a & (carry << i)) > 0)
                carry = 1;
            else if ((bit_b & (carry << i)) > 0)
                carry = 1;
            else
                carry = 0;
        }
        return sum;
    }
};
