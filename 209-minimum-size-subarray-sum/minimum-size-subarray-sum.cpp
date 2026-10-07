class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left = 0 , right = 0;
        int n = nums.size();
        long long sum = 0;
        int mini = INT_MAX;
        while(right < n){
            sum += nums[right];
            while(sum >= target){
                mini = min(mini , right - left + 1);
                sum -= nums[left];
                left++;
            }
            right++;
        }
        if(mini == INT_MAX) return 0;
        return mini;
    }
};