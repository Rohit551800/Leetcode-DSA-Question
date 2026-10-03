class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if (grid[0][0] == 1 || grid[n-1][n-1] == 1) return -1;
        queue<pair<int , pair<int , int>>>q;
        vector<vector<int>>dist(n , vector<int>(n , INT_MAX));
        dist[0][0] = 1;
        q.push({1 , {0 , 0}});

        while(!q.empty()){
            int prevDis = q.front().first;
            int row = q.front().second.first;
            int col = q.front().second.second;
            q.pop();
            for(int delrow=-1 ;delrow<=1;delrow++){
                for(int delcol = -1 ;delcol <=1 ;delcol++){
                    int rowx = row + delrow;
                    int colx = col + delcol;

                    if(rowx < 0 || rowx >= n) continue;
                    if(colx < 0 || colx >= n) continue;

                    if(grid[rowx][colx] == 1) continue;
                    if(dist[rowx][colx] > prevDis + 1){
                        dist[rowx][colx] = 1 + prevDis;
                        q.push({prevDis + 1 , {rowx , colx}}); 
                    }
                }
            }
        }
        if(dist[n-1][n-1] == INT_MAX) return -1;
        return dist[n-1][n-1];
    }
};