class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        queue<pair<int,int>> q;
        
        int n = image.size();
        int m = image[0].size();
        int value = -1;
        value = image[sr][sc];
        if (value == color) return image;
        //adding node in queue
           q.push({sr,sc});
                    image[sr][sc] = color;         
        vector<vector<int>> dir = {{1,0}, {0,-1}, {-1,0}, {0,1}};
        while(!q.empty()){
            int i = q.front().first;
            int j = q.front().second;
            q.pop();
            for(auto d : dir){
                int x = i + d[0];
                int y = j + d[1];

                if(x>=0 && x < n && y >= 0 && y < m && image[x][y] == value){
                    image[x][y] = color;
                    q.push({x,y});
                }
            }
        }
        return image;
    }
};
