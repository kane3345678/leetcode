Find All Anagrams in a String
class Solution {
public:
    bool matchstr(string x, string y) {
        unordered_map<char, int> h;
        for (auto i : x)
            h[i] += 1;
        
        for (int i = 0; i < y.size(); i++) {
            if (h[y[i]] > 0)
                h[y[i]] -= 1;
            else
                return false;
        }
        return true;
    }
    vector<int> findAnagrams(string s, string p) {
        int n = s.size();
        int m = p.size();
        vector<int> ans;
        bool found = false;
        cout<<n<<", "<<m<<endl;

        for (int i = 0; i < n - m + 1; i++) {
            string tmp = s.substr(i, m);

            if (!found) {
                if (i > 0 && tmp[tmp.size() - 1] == s[i-1])
                    continue;
                if (matchstr(s.substr(i, m), p)) {
                    ans.push_back(i);
                    found = true;
                }
            }
            else {
                if (s[i - 1] == tmp[tmp.size() - 1]) 
                    ans.push_back(i);
                else 
                    found = false;
            }
        }
        return ans;
    }
};
