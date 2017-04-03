Longest Palindromic Substring

class Solution {
public:
    //check string if it's Palindromic 
    string longestPalindrome(string s) {
        int longest = 0;
        string ans = "";

        for (int i = 0; i < s.size(); i++)
        {
            int x = i - 1, y = i + 1, cnt = 1;
            while(x >= 0 || y < s.size())
            {
                if (x >= 0 && s[x] == s[x + 1] && s[x+1] == s[i]){
                    cnt++;
                    x--;
                    continue;
                } else if (y < s.size() && s[y] == s[y - 1]&& s[y-1] == s[i]){
                    cnt++;
                    y++;
                    continue;
                }
                if (x < 0 || y >= s.size())
                    break;
                if (s[x] != s[y])
                    break;
                cnt+=2;
                x--;
                y++;
            }
            
           if (cnt > longest) {
                x++;
                y--;
                cout << x<<"  "<< y<<endl;
                longest = cnt;
                ans = s.substr(x, y-x +1);
                cout << ans<<endl;;
            }
            
        }
        
            
        return ans;
    }
};







