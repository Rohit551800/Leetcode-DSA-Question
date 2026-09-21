class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>>vis(n , vector<int>(m , 0));
        vector<vector<int>>dist(n , vector<int>(m , 0));

        queue<pair<pair<int , int> , int>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j] == 0){
                    q.push({{i , j} , 0});
                    dist[i][j] = 0;
                    vis[i][j] = 1;
                }
            }
        }
        vector<int>vr = {-1 , 1 , 0 , 0};
        vector<int>vc = {0 , 0 , -1 , 1};

        while(!q.empty()){
            int row = q.front().first.first;
            int col = q.front().first.second;
            int dis = q.front().second;

            q.pop();

            for(int i=0;i<4;i++){
                int nrow = row + vr[i];
                int ncol = col + vc[i];
                if(nrow < 0 || nrow >= n) continue;  
                if(ncol < 0 || ncol >= m) continue;
                if(!vis[nrow][ncol]){
                    vis[nrow][ncol] = 1;
                    dist[nrow][ncol] = dis + 1;
                    q.push({{nrow , ncol} , dis + 1});
                }
            }
        }
        return dist;
    }
};