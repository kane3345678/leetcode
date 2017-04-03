https://leetcode.com/problems/h-index/#/description

class Solution {
public:
    int hIndex(vector<int>& citations) {
        if (citations.size() == 0)
        {
            return 0;
        }
        if (citations.size() == 1 && citations.back()==1)
        {
            return 1;
        }
        
        std::sort(citations.begin(), citations.end());
        int x = 0;
        int y = citations.back();
        int ans = 0;
        cout << x<< ":"<<y<<endl;
        while (x<=y){
            cout << x<< ":"<<y<<endl;
            int mid = (x + y) /2;
            vector<int> a;
            for (int i=0; i< citations.size();i++)
            {
                if (citations[i]>= mid){
                    a.push_back(1);
                }
            }
            cout << mid<< "===="<<a.size()<<endl;
            if (a.size() >= mid){
                ans = max(mid, ans);
                
                x = mid + 1;
            } else {
                
                y = mid - 1 ;
            }
        }
        return ans;
    }
};


