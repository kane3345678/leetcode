https://leetcode.com/submissions/detail/98849588/
Spiral Matrix II
class Solution {
public:
	bool chk_out_bound (string &dir, vector<vector<int>> &ans, int n, int &x, int &y) {
	    bool changed = false;
		if (y >= n) {
			y = n - 1;
			x += 1;
			dir = "down";
			changed = true;
		}
		else if (x >= n) {
			x = n -1;
			y -= 1;
			dir = "left";
			changed = true;
		}
		else if (x < 0) {
			x = 0;
			y += 1;
			dir = "right";
			changed = true;
		}
		else if (y < 0) {
			y = 0;
			x -= 1;
			dir = "up";
			changed = true;
		}
		return changed;
	}
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans (n, vector<int>(n, 0));

		string dir = "right";
		int x = 0, y = 0;
        for (int i = 1; i <= n*n; i++) {
            
			ans[x][y] = i;
			if (dir == "right")				
				y += 1;
			else if(dir == "down")
				x += 1;
			else if(dir == "up")
				x -= 1;
			else if(dir == "left")
				y -= 1;
			bool changed = chk_out_bound(dir, ans, n, x, y);
           // cout<<x<<" ====  "<<y<<"****"<<changed<<endl;

			if (!changed && ans[x][y] != 0) {
				if (dir == "right") {
					y -= 1; x += 1;
					dir = "down";
				}
				else if(dir == "down") {
					x -= 1; y -= 1;
					dir = "left";
				}
				else if(dir == "up") {
					x += 1; y += 1;
					dir = "right";
				}
				else if(dir == "left") {
					y += 1; x -= 1;
					dir = "up";
				}
				
			}

		}
		return ans;
    }
};