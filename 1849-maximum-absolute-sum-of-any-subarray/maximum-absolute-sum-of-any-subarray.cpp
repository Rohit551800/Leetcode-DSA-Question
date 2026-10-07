class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int n = nums.size();
        int maxi = nums[0];
        int mini = nums[0];
        int maxSum = nums[0];
        int minSum = nums[0];

        for(int i=1;i<n;i++){
            maxSum = max(nums[i] , maxSum + nums[i]);
            minSum = min(nums[i] , minSum + nums[i]);

            maxi = max(maxi , maxSum);
            mini = min(mini , minSum);
        }
        return max(abs(maxi) , abs(mini));
    }
};