class Solution {
public:
    int totalCost(vector<int>&cost , int n , vector<int>&dp){
        if(n < 0) return 0;
        if(n == 0) return cost[0];
        if(n == 1) return cost[1];
        if(dp[n] != -1) return dp[n];
        
        int pick = cost[n] + totalCost(cost , n-2 , dp);
        int not_pick = cost[n] + totalCost(cost , n-1 , dp);

        return dp[n] = min(pick , not_pick);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int>dp(cost.size() , -1);
        int cost1 = totalCost(cost ,  cost.size() -1 , dp);
        int cost2 = totalCost(cost , cost.size() -2 , dp);

        return min(cost1 , cost2);
    }
};