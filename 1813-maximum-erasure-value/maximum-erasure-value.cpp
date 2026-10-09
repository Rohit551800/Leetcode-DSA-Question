class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int , int>mpp;
        int left = 0 , right = 0;
        int maxi = INT_MIN;
        int sum = 0;
        for(int right=0;right<n;right++){
            mpp[nums[right]]++;
            sum += nums[right];
            while(mpp[nums[right]] > 1){
                sum -= nums[left];
                mpp[nums[left]]--;
                left++;
            }
            maxi = max(maxi , sum);
        }
        return maxi ;
    }
};