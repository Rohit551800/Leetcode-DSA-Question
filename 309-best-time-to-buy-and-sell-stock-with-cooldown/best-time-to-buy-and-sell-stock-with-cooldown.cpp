class Solution {
public:
    int f(int ind , int buy ,int profit, vector<int>&prices , vector<vector<int>>&dp){
        if(ind == prices.size() || ind == prices.size()+1) return 0;
        if(dp[ind][buy] != -1) return dp[ind][buy];
        if(buy){
            profit = max(-prices[ind] + f(ind + 1 , 0 , profit , prices ,dp) , 0 + f(ind + 1 , 1 , profit , prices ,dp));
        }
        else{
            profit = max(+prices[ind] + f(ind + 2 , 1 , profit , prices ,dp) , 0 + f(ind + 1 , 0 , profit , prices ,dp));
        }

        return dp[ind][buy] = profit;
    }
    int maxProfit(vector<int>& prices) {
        // int n = prices.size();
        // vector<vector<int>>dp(prices.size() , vector<int>(2 , -1));
        // return f(0 , 1 , 0 ,prices , dp);


        // Tabulation
        int n = prices.size();
        vector<vector<int>>dp(prices.size() + 2, vector<int>(2 , 0));
        dp[n][0] =  dp[n][1] = 0;
        for(int ind = n-1 ; ind>= 0;ind--){
            for(int buy=0;buy<=1;buy++){
                int profit = 0;
                if(buy){
                    profit = max(-prices[ind] + dp[ind + 1][0], 0 + dp[ind + 1][1]);
                }
                else{
                    profit = max(prices[ind] + dp[ind + 2][1], 0 + dp[ind + 1][0]);
                }
                dp[ind][buy] = profit;
            }
        }
        return dp[0][1];


        // vector<int>curr(2 , 0) , ahead1(2 , 0) ;
        // vector<int> ahead2(2, 0);
        // prev[0] = prev[1] = 0;
        // for(int ind = n-1 ; ind>= 0;ind--){
        //     for(int buy=0;buy<=1;buy++){
        //         int profit = 0;
        //         if(buy){
        //             profit = max(-prices[ind] + ahead1[0], 0 + prev[1]);
        //         }
        //         else{
        //             profit = max(prices[ind] + prev[1], 0 + prev[0]);
        //         }
        //         ahead[buy] = profit;
        //     }
        //     prev = ahead;
        //     ahead = ahead2;
        // }
        // return max(prev[1] , ahead[1]);
    }
};