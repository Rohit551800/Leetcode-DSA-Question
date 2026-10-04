class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();

        vector<vector<int>>dist(n , vector<int>(m , INT_MAX));
        dist[0][0] = 0;

        priority_queue<pair<int , pair<int , int>> , vector<pair<int , pair<int , int>>> , greater<pair< int , pair<int , int>>>>pq;

        pq.push({0 , {0 , 0}});
        vector<int>rows = {0 , 0 , 1 , -1};
        vector<int>cols = {-1 , 1 , 0 , 0};

        while(!pq.empty()){
            int prevDiff = pq.top().first;
            int row = pq.top().second.first;
            int col = pq.top().second.second;
            pq.pop();

            for(int i=0;i<4;i++){
                int rowx = row + rows[i];
                int colx = col + cols[i];

                if(rowx < 0 || rowx >= n) continue;
                if(colx < 0 || colx >= m) continue;

                int diff =max(prevDiff , abs(heights[row][col] - heights[rowx][colx]));

                if(dist[rowx][colx] > diff) {
                    dist[rowx][colx] = diff;
                    pq.push({dist[rowx][colx]  , {rowx , colx}});
                }
            }
        }
        return dist[n-1][m-1];
    }
};