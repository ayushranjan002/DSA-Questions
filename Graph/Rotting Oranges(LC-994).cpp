class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        int freshorange = 0;
        int minutes = 0;

        int rows = grid.size();
        int cols = grid[0].size();

        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                if(grid[i][j] == 2) {
                    q.push({i, j});
                }
                if(grid[i][j] == 1) {
                    freshorange++;
                }
            }
        }

        if(freshorange == 0) return 0;
        if(q.empty()) return -1;

        vector<vector<int>> dir = {{1,0}, {0,-1}, {-1,0}, {0,1}};

        
        while(!q.empty()) {
            int size = q.size();
            bool newRot = false;

            for(int k = 0; k < size; k++) {
                int i = q.front().first;
                int j = q.front().second;
                q.pop();

                for(auto d : dir) {
                    int x = i + d[0];
                    int y = j + d[1];

                    if(x >= 0 && x < rows && y >= 0 && y < cols && grid[x][y] == 1) {
                        grid[x][y] = 2;
                        q.push({x, y});
                        freshorange--;
                        newRot = true;
                    }
                }
            }

            if(newRot) minutes++;  
        }

        return freshorange == 0 ? minutes : -1;
    }
};
