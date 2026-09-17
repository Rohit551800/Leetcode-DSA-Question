class Solution {
public:
    void bfs(int i , int j , vector<vector<int>>&vis , vector<vector<char>>grid){
        int n = grid.size();
        int m = grid[0].size();

        vis[i][j] = 1;
        queue<pair<int,int>>q;
        q.push({i , j});


        int delrow[] = {-1, 1, 0, 0};
        int delcol[] = {0, 0, -1, 1};

        while(!q.empty()){
            auto node = q.front();
            int x = node.first;
            int y = node.second;

            q.pop();

            for (int k = 0; k < 4; k++) {

                int row = x + delrow[k];
                int col = y + delcol[k];

                if (row >= 0 && row < n &&
                    col >= 0 && col < m &&
                    grid[row][col] == '1' &&
                    !vis[row][col]) {

                    vis[row][col] = 1;
                    q.push({row, col});
                }
            }

        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int count = 0;
        vector<vector<int>>vis(n , vector<int>(m , 0)) ;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == '1' && !vis[i][j]){
                    count += 1;
                    bfs( i , j , vis , grid);
                }
            }
        }
        return count;
    }
};