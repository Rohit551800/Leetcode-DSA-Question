class Solution {
public:
    int func(int ind , vector<int>&p , vector<int>&dp){
        if(ind <  0) return 0;
        if(dp[ind] != -1) return dp[ind];
        //take
        int take = p[ind] + func(ind -2 , p , dp);
        //not_take
        int not_take = func(ind-1 , p , dp);

        return dp[ind] = max(take , not_take);
    }

    int deleteAndEarn(vector<int>& nums) {
        int n = nums.size();
        int maxi = *max_element(nums.begin() , nums.end());
        vector<int>dp(maxi +1 , -1);
        vector<int>p(maxi+1 , 0);


        for(auto it : nums){
            p[it] += it;
        }
        return func(maxi , p , dp);
    }
};