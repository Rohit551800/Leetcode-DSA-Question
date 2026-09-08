class Solution {
public:
    int f(int ind , int prevInd , vector<int>&nums){
        if(ind == nums.size()) return 0;

        int not_take = f(ind + 1 , prevInd , nums);
        int take = 0;
        if(prevInd == -1 || nums[ind] % nums[prevInd] == 0 ||
             nums[prevInd] % nums[ind] == 0)
             take =  1 + f(ind + 1 , ind , nums);

        return max(take , not_take);
    }
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return {nums[0]};
        // int ans = f(0 , -1 , nums);
        // return {ans};

        //Tabulation
        // vector<vector<int>>dp(n+1 , vector<int>(n+1 , 0));

        // for(int ind=n-1 ; ind>= 0 ; ind--){
        //     for(int prevInd = n-1 ; prevInd >= -1 ;prevInd--){
        //         int not_take = dp[ind + 1][prevInd+1];
        //         int take = 0;
        //         if(prevInd == -1 || nums[ind] % nums[prevInd] == 0 ||
        //              nums[prevInd] % nums[ind] == 0)
        //             take = 1 + dp[ind + 1][ind + 1];

        //         dp[ind][prevInd+1] = max(take , not_take);
        //     }
        // }
        // cout<<dp[0][0]<<endl;
        // return {};


        //Code for printing 

        vector<int>dp(n , 1), hash(n , 0);
        int lastInd = 0 , maxi = 1;
        sort(nums.begin() , nums.end());

        for(int i=0;i<n;i++){
            hash[i] = i;
            for(int j=0;j<i;j++){
                if(nums[i] % nums[j] == 0 && dp[i] < dp[j] + 1){
                    dp[i] = dp[j] + 1;
                    hash[i] = j;
                }
            }
            if(maxi < dp[i]){
                maxi = dp[i];
                lastInd = i;
            }
        }

        vector<int>temp;
        temp.push_back(nums[lastInd]);
        while(lastInd != hash[lastInd]){
            lastInd = hash[lastInd];
            temp.push_back(nums[lastInd]);
        }

        return temp;
    }
};