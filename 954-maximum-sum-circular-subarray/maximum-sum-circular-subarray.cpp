class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();
        int total = 0;
        for(auto it : nums){
            total += it;
        }
        int maxi = nums[0] , mini = nums[0];
        int maxSum = nums[0] , minSum = nums[0];

        for(int i=1;i<n;i++){
            maxSum = max(maxSum + nums[i] , nums[i]);
            minSum = min(minSum + nums[i] , nums[i]);

            maxi = max(maxi , maxSum);
            mini = min(mini , minSum);
        }
        if(maxi < 0) return maxi ;
        return max(maxi , total - mini);
    }
};