class Solution {
public:
    int f(int ind , int T , vector<int>&nums , vector<unordered_map<int ,int>>&dp){
        //Base Case;
        if(ind == 0){
            int ways = 0;
            if(nums[ind] == T) ways += 1;
            if(-nums[ind] == T) ways += 1;
            return ways;
        }
        //Explore all paths
        if(dp[ind].count(T)) return dp[ind][T];
        int neg = f(ind - 1 , T - nums[ind] , nums , dp);
        int pos = f(ind - 1 , T + nums[ind] , nums , dp);

        return dp[ind][T] = neg + pos;
    }
    int findTargetSumWays(vector<int>& nums, int T) {
        int n = nums.size();
        vector<unordered_map<int , int>>dp(n);
        return f(n-1 , T , nums , dp);
    }
};