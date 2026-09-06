class Solution {
public:
    int f(int ind , int prevInd , vector<int>&nums , vector<vector<int>>&dp){
        // Base Case
        if(ind == nums.size()) return 0;
        // Explore all the paths //Take not_take problem
        if(dp[ind][prevInd+1] != -1) return dp[ind][prevInd+1];
        int not_take = f(ind + 1 , prevInd , nums , dp);
        int take = 0;
        if(prevInd == -1|| nums[ind] > nums[prevInd]){
            take = max(1 + f(ind + 1 , ind , nums , dp) , 0 + f(ind + 1 , prevInd , nums ,dp));
        }
        // Return the maxLen
        return dp[ind][prevInd+1] = max(not_take , take);
    }
    int lengthOfLIS(vector<int>& nums) {
        // int n = nums.size();
        // vector<vector<int>>dp(n, vector<int>(n+1, -1));
        // return f(0 , -1 , nums , dp);

        // vector<vector<int>>dp(n+1, vector<int>(n+1, 0));
        // dp[0][0] = 0;
        // for(int ind=n-1;ind>=0;ind--){
        //     for(int prevInd=n-1;prevInd>=-1;prevInd--){
        //         int len= dp[ind + 1][prevInd+1];
        //         if(prevInd == -1 || nums[ind] > nums[prevInd]){
        //             len = max(len , 1 + dp[ind + 1][ind+1]);
        //         }
        //         // Return the maxLen
        //         dp[ind][prevInd+1] = len;
        //     }
        // }
        // return dp[0][0];

        //Space Optimization

        int n = nums.size();

        vector<int>curr(n+1, 0) ,  ahead(n+1 , 0);

        for(int ind=n-1;ind>=0;ind--){
            for(int prevInd=n-1;prevInd>=-1;prevInd--){
                int len = ahead[prevInd+1];
                if(prevInd == -1 || nums[ind] > nums[prevInd]){
                    len = max(len , 1 + ahead[ind+1]);
                }
                // Return the maxLen
                curr[prevInd+1] = len;
            }
            ahead = curr;
        }
        return curr[0];
    }
};