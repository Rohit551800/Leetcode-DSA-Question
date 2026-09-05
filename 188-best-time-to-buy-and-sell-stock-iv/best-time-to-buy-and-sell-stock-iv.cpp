class Solution {
public:
    int f(int ind , int buy ,int profit, vector<int>&prices ,int T , vector<vector<vector<int>>>&dp){
        if(ind == prices.size() || T == 0) return 0;
        if(dp[ind][buy][T] != -1) return dp[ind][buy][T];
        if(buy && T){
            profit = max(-prices[ind] + f(ind + 1 , 0 , profit , prices,T ,dp) , 0 + f(ind + 1 , 1 , profit , prices,T ,dp));
        }
        else{
            profit = max(+prices[ind] + f(ind + 1 , 1 , profit , prices,T-1 ,dp) , 0 + f(ind + 1 , 0 , profit , prices,T ,dp));
        }

        return dp[ind][buy][T] = profit;
    }
    int maxProfit(int k ,vector<int>& prices) {
        int n = prices.size();
        //Recursion + Memoization
        // vector<vector<vector<int>>>dp(prices.size() , vector<vector<int>>(2 , vector<int>(T+1 , -1)));
        // return f(0 , 1 , 0 ,prices , 2 , dp);

        // Tabulation
        vector<vector<vector<int>>>dp(prices.size()+1 , vector<vector<int>>(2 , vector<int>(k+1 , 0)));

        // Base Case
        // if(ind == prices.size() || T == 0) return 0;
        //Explore all the paths
        for(int ind = n-1;ind >= 0;ind--){
            for(int buy = 0;buy <= 1 ; buy++){
                for(int T = k;T > 0 ; T--){
                    int profit = 0;
                    if(buy && T){
                        profit = max(-prices[ind] + dp[ind + 1][0][T], 0 + dp[ind + 1][1][T]);
                    }
                    else{
                        profit = max(+prices[ind] + dp[ind + 1][1][T-1], 0 + dp[ind + 1][0][T]);
                    }

                    dp[ind][buy][T] = profit;
                }
            }
        }
        return dp[0][1][k];
    }
};