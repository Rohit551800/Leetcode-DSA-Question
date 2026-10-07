class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();
        int totalSum = 0;
        for(auto it : nums) totalSum += it;

        int maxi = nums[0];
        int mini = nums[0];
        int maxSum = nums[0];
        int minSum = nums[0];

        for(int i=1;i<n;i++){
            maxSum = max(nums[i] , maxSum + nums[i]);
            minSum = min(nums[i] , minSum + nums[i]);

            maxi = max (maxi , maxSum);

            mini = min(mini , minSum);
        }
        if(maxi < 0) return maxi;
        return max(maxi , totalSum - mini);
    }
};