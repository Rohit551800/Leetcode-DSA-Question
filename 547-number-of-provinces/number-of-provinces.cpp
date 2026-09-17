class Solution {
public:
    void bfs(int start , vector<int>& vis , vector<vector<int>>& isConnected){
        int n = isConnected.size();
        vis[start] = 1;

        queue<int>q;
        q.push(start);

        while(!q.empty()){
            int node = q.front();
            q.pop();

            for(int i=0;i<n;i++){
                if(isConnected[node][i] == 1 && !vis[i]){
                    vis[i] = 1;
                    q.push(i);
                }
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();

        vector<int>vis(n , 0);
        int count = 0;

        for(int i=0;i<n;i++){
            if(!vis[i]){
                bfs(i , vis , isConnected);
                count += 1;
            }
        }
        return count ;
    }
};