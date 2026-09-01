class Solution {
public:
    int f(int ind , int T , vector<int>&nums){
        //Base Case;
        if(ind == 0){
            int ways = 0;
            if(nums[ind] == T) ways += 1;
            if(-nums[ind] == T) ways += 1;
            return ways;
        }
        //Explore all paths

        int neg = f(ind - 1 , T - nums[ind] , nums);
        int pos = f(ind - 1 , T + nums[ind] , nums);

        return neg + pos;
    }
    int findTargetSumWays(vector<int>& nums, int T) {
        int n = nums.size();
        return f(n-1 , T , nums);
    }
};