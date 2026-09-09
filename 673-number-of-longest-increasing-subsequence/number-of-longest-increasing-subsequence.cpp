class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return 1;
        vector<int>dp(n , 1);
        vector<int>count(n , 1);
        int maxi = 0;
        for(int i=0;i<n;i++){
            for(int prev=0;prev <= i-1;prev++){
                if(nums[i] > nums[prev] && dp[i] < dp[prev] + 1){
                    dp[i] = dp[prev] + 1;

                    count[i] = count[prev];
                }
                else if(dp[i] == dp[prev] + 1){
                    count[i] += count[prev];
                }
                maxi = max (maxi , dp[i]);
            }
        }
        int ans = 0;
        for(int i=0;i<n;i++){
            if(dp[i] == maxi){
                ans += count[i];
            }
        }
        return ans;
    }
};