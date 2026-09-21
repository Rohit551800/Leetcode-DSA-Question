class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>>vis(n , vector<int>(m , 0));
        
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++){
            if(grid[i][0] == 1){
                vis[i][0] = 1;
                q.push({i , 0});
            }
            if(grid[i][m-1] == 1){
                vis[i][m-1] = 1;
                q.push({i , m-1});
            }
        }

        for(int i=0;i<m;i++){
            if(grid[0][i] == 1){
                vis[0][i] = 1;
                q.push({0 , i});
            }
            if(grid[n-1][i] == 1){
                vis[n-1][i] = 1;
                q.push({n-1 , i});
            }
        }

        vector<int>vr = {1 , -1 , 0 , 0};
        vector<int>vc = {0 , 0 , -1 , 1};

        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;

            q.pop();

            for(int i=0;i<4;i++){
                int nrow = row + vr[i];
                int ncol = col + vc[i];

                if(nrow < 0 || nrow >= n) continue;
                if(ncol < 0 || ncol >= m) continue;

                if(!vis[nrow][ncol] && grid[nrow][ncol] == 1){
                    vis[nrow][ncol] = 1;
                    q.push({nrow , ncol});
                }
            }
        }
        int res = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid[i][j] == 1) res++;
            }
        }
        return res;
    }
};