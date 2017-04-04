class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if (grid.size() == 0)
            return 0;
        int ans = 0;
        for (int i = 0; i < grid.size(); i++)
        {
            if(i > 0)
                grid[i][0] = grid[i-1][0] + grid[i][0];
            for(int j = 1; j < grid[i].size(); j++)
            {
                if (i == 0)
                    grid[0][j] = grid[i][j - 1] + grid[i][j];
                else
                    grid[i][j] = min(grid[i-1][j], grid[i][j - 1]) + grid[i][j];
            }
        }
        return grid[grid.size() - 1][grid[0].size()-1];
    }
};
