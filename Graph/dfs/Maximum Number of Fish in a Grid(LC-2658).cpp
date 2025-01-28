class Solution {
public:
    const vector<vector<int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    int dfs(int r, int c, vector<vector<int>>& grid, vector<vector<bool>>& visited) {
        if (r < 0 || r >= grid.size() || c < 0 || c >= grid[0].size() || grid[r][c] == 0 || visited[r][c]) 
            return 0;
        visited[r][c] = true;
        int fishCount = grid[r][c];
        for (const auto& dir : directions) 
            fishCount += dfs(r + dir[0], c + dir[1], grid, visited);
        return fishCount;
    }
    int findMaxFish(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size(),maxF = 0;
        vector<vector<bool>> visited(rows, vector<bool>(cols,false));
        /*
        below line checks whether grid is unvited and a water cell
        */
        for (int r = 0; r < rows; r++) 
            for (int c = 0; c < cols; c++) 
                if (grid[r][c] > 0 && !visited[r][c]) 
                    maxF = max(maxF, dfs(r, c, grid, visited));
        return maxF;
    }
};
