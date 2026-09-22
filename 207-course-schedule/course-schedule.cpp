class Solution {
public:
    bool canFinish(int V, vector<vector<int>>& edges) {
        vector<vector<int>>adj(V);
        for(auto it : edges){
            int u = it[0];
            int v = it[1];

            adj[u].push_back(v);
        }
        queue<int>q;
        vector<int>indeg(V);
        for(int i=0;i<V;i++){
            for(auto it : adj[i]){
                indeg[it]++;
            }
        }

        for(int i=0;i<V;i++){
            if(indeg[i] == 0) q.push(i);
        }

        vector<int>ans;

        while(!q.empty()){
            int node = q.front();
            q.pop();
            ans.push_back(node);

            for(auto it : adj[node]){
                if(indeg[it]){
                    indeg[it]--;
                }
                if(!indeg[it]){
                    q.push(it);
                }
            }
        }
        if(ans.size() == V) return true;
        return false;
    }
};