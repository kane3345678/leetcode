class Solution {
public:

#define folder_l(s) count(s.begin(), s.end(), '\t')	
#define is_folder(s) (s.find('.') == string::npos)
	int m;
	void traverse(vector<string> &p, int level, string path) {
		for (int i = 0; i < p.size(); i++) {
		    cout<<path<<", "<<p[i]<<endl;
			if (folder_l(p[i]) < level)
				return;
			else if(folder_l(p[i]) == level) {
			    
				if (is_folder(p[i])) {
					vector<string> n (p.begin() + i + 1, p.end());
					traverse(n, level + 1, path + p[i]);
				}
				else {
					int cnt = count(path.begin(), path.end(), '\t');
					m = max(m, int(path.size() + p[i].size() - cnt));
				}
			}
		}
	}
	
    int lengthLongestPath(string input) {
		m = 0;
		vector<string> p;
		string a;
		istringstream iss(input);
		while (getline(iss, a, '\n' )) {
				p.push_back(a);
		}
		traverse(p, 0, "");
		return m;
    }
};