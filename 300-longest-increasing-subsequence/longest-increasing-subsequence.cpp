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
        int n = nums.size();
        vector<vector<int>>dp(n, vector<int>(n+1, -1));
        return f(0 , -1 , nums , dp);
    }
};