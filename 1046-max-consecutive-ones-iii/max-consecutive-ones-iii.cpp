class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int left = 0 , right = 0 , maxi = INT_MIN;
        int count = 0;
        while(right < n){
            if(nums[right] == 0) count++;
            while(right < n && count > k){
                if(nums[left] == 0) count--;
                left++;
            }
            maxi = max(maxi , right-left+1);
            right++;
        }
        return maxi;
    }
};