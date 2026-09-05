class Solution {
public:
    long long maximumProfit(vector<int>& prices, int k) {
        int n = prices.size();
        long long NEG = -1e18;
        // Tabulation
        vector<vector<vector<long long>>>dp(prices.size()+1 , vector<vector<long long>>(3 , vector<long long>(k+1 , 0)));

        // Base Case
        for (int T = 0; T <= k; T++) {
            dp[n][0][T] = 0;
            dp[n][1][T] = NEG;
            dp[n][2][T] = NEG;
        }
        //Explore all the paths
        for(int ind = n-1;ind >= 0;ind--){
            for(int buy = 0;buy <= 2 ; buy++){
                // 1-> free 
                // 2->normal buy 
                // 3->Short selling
                for(int T = k;T > 0 ; T--){
                    if(buy == 0){
                        dp[ind][buy][T] = max( dp[ind+1][0][T] , max(1LL*-prices[ind] +
                        dp[ind+1][1][T] , 1LL*prices[ind] + dp[ind+1][2][T]));
                    }
                    else if(buy == 1){
                        dp[ind][buy][T] = max(dp[ind+1][1][T] , 1LL* prices[ind] + dp[ind+1][0][T-1]);
                    }
                    else{
                        dp[ind][buy][T] = max(dp[ind+1][2][T] , 1LL* -prices[ind] + dp[ind+1][0][T-1]);
                    }
                }
            }
        }
        return dp[0][0][k];
    }
};