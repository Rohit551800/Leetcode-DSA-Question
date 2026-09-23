class Solution {
public:
    bool dfs(int node , vector<vector<int>>&graph , vector<int>&vis , vector<int>&pathVis , vector<int>&check){
        check[node] = 0;
        vis[node] = 1;
        pathVis[node] = 1;

        for(auto it : graph[node]){
            if(!vis[it]){
                if(dfs(it , graph , vis , pathVis , check) == true)
                return true;
            }
            else if(pathVis[it]) return true;
        }
        check[node] = 1;
        pathVis[node] = 0;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>>adj(n);

        vector<int>vis(n);
        vector<int>pathVis(n);
        vector<int>ans;
        vector<int>check(n , 0);

        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(i , graph , vis , pathVis , check);
            }
        }
        for(int i=0;i<n;i++){
            if(check[i]){
                ans.push_back(i);
            }
        }
        return ans;
    }
};