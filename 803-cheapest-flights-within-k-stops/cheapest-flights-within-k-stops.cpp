class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int , int>>> adj(n);
        for(auto it : flights){
            int u = it[0];
            int v = it[1];
            int p = it[2];

            adj[u].push_back({v , p});
        }
        vector<int>dist(n , INT_MAX);
        dist[src] = 0;
        // {stop , { node , price}} 
        queue<pair<int , pair<int , int>>>q;

        q.push({0 , {src , 0}});

        while(!q.empty()){
            int stop = q.front().first;
            int city = q.front().second.first;
            int price = q.front().second.second;
            q.pop();

            if(stop > k) continue;
            
            for(auto it : adj[city]){
                int nbr = it.first;
                int p = it.second;

                int totalP = p + price;
                
                if(dist[nbr] > totalP){
                    dist[nbr] = totalP;
                    q.push({stop+1 , {nbr , totalP}});
                }
            }
        }
        if(dist[dst] == INT_MAX) return -1;
        return dist[dst];
    }
};