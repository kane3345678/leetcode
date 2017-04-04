01 Matrix
https://leetcode.com/problems/01-matrix/#/description
class point {
public:
    int x;
    int y;
    point(int _x, int _y): x(_x), y(_y){};

};
#define MAX 30000
class Solution {
public:
    int n;

    int bst(point p, point s, vector<vector<int>> m, vector<vector<int>> &flag)
    {
        if ((p.x < 0) || (p.x >= n) || (p.y < 0) || (p.y >= n))
            return MAX;
        if (flag[p.x][p.y] == -1)
            return MAX;
    
        flag[p.x][p.y] = -1;

        if(m[p.x][p.y] == 0)
            return abs(s.x - p.x) + abs(s.y - p.y);

        int len = MAX;
        len = min(len, bst(point(p.x + 1, p.y), s, m, flag));
        len = min(len, bst(point(p.x - 1, p.y), s, m, flag));
        len = min(len, bst(point(p.x, p.y + 1), s, m, flag));
        len = min(len, bst(point(p.x, p.y - 1), s, m, flag));
        return len;
    }
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        n = matrix.size();
        cout<<n<<endl;
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                if (matrix[i][j] != 0) {
                    vector<vector<int>> flag(n, vector<int>(n, 0));
                    int len = MAX;
                    flag[i][j] = -1;
                    len = min(len, bst(point(i+1, j), point(i, j), matrix, flag));
                    len = min(len, bst(point(i-1, j), point(i, j), matrix, flag));
                    len = min(len, bst(point(i, j+1), point(i, j), matrix, flag));
                    len = min(len, bst(point(i, j-1), point(i, j), matrix, flag));
                    matrix[i][j] = len;
                }
            }
        }
        return matrix;
    }
};


