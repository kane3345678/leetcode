class coor {
public:
	int x;
	int y;
	coor(int _x, int _y) : x(_x), y(_y){};
	coor(){};
};

class Solution {
public:
	vector<coor> sol;
	void merge(int x, int y) {
		coor c(x, y);

		if (sol.size() == 0){
			sol.push_back(c);
			return;
		}
		else {
			coor last;
			last = sol.back();

			if (x - last.y == 1){
				last.y = y;
				sol.pop_back();
				merge(last.x, last.y);
			}
			else if ((x - last.x) == -1 && (last.y - y) == -1){
				last.x = x;
				last.y = y;
				sol.pop_back();
				merge(last.x, last.y);
			}
			else{
				sol.push_back(c);
			}
		}
	}
	int longestValidParentheses(string s) {
		int i = 0;
		vector<int> stack; // for left parentheses
		while (i < s.size())
		{
			if (s[i] == '(')
				stack.push_back(i);
			else if (s[i] == ')') {
				if (stack.size() > 0){
					merge(stack.back(), i);
					stack.pop_back();
				}
			}
			i++;
		}
		int biggest = 0, sum = 0;
		for (int i = 0; i < sol.size(); i++)
		{
			sum = (sol[i].y - sol[i].x) + 1;
			biggest = (sum > biggest) ? sum : biggest;
		}
		return biggest;
	}
};

