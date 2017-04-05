Island Perimeter
class Solution {
public:
    int get_nbr(int x, int y, vector<vector<int>> &grid)
    {
        int w = grid.size() - 1;
        int h = grid[0].size() - 1;
        int cnt = 0;
        if (x == 0 || (x > 0 && grid[x - 1][y] == 0))
            cnt++;
        if (x == w || (x < w && grid[x + 1][y] == 0))
            cnt++;
        if (y == h || (y < h && grid[x][y + 1] == 0))
            cnt++;
        if (y == 0 || (y > 0 && grid[x][y - 1] == 0))
            cnt++;
        return cnt;
    }
    int islandPerimeter(vector<vector<int>>& grid) {
        int n = 0;
        for (int i = 0; i < grid.size(); i++)    
        {
            for (int j = 0; j < grid[i].size(); j++)
            {
                if(grid[i][j] == 1)
                    n += get_nbr(i, j, grid);
            }
        }
        return n;
    }
};

