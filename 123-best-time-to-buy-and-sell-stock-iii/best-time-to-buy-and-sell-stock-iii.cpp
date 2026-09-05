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
    int maxProfit(vector<int>& prices) {
        vector<vector<vector<int>>>dp(prices.size() , vector<vector<int>>(2 , vector<int>(3 , -1)));
        return f(0 , 1 , 0 ,prices , 2 , dp);
    }
};