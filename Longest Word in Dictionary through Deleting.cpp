Longest Word in Dictionary through Deleting
https://leetcode.com/submissions/detail/99053689/
class Solution {
public:
    string cmp_lexi(string a, string b) {
        if (b == "")
            return a;
        for (int i = 0; i < a.size(); i++) {
            if (a[i] < b[i])
                return a;
            else if (a[i] > b[i])
                return b;
        }
        return a;
    }
    string findLongestWord(string s, vector<string>& d) {
        string ans;
        int i = 0;
        for (auto w : d) {
            int j = 0;
            for (i = 0; i < s.size(); i++) {
                if (s[i] == w[j])
                    j++;
            }
            if (j == w.size() ) {
                if (w.size() > ans.size())
                    ans = w;
                else if (w.size() == ans.size())
                    ans = cmp_lexi(w, ans);
            }
        }
        return ans;
    }
};