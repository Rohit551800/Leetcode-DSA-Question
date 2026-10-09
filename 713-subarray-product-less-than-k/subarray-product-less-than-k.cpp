class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k <= 1) return 0;
        int n = nums.size();
        int count = 0;
        long long prod = 1;
        int left = 0 , right = 0;

        for(right = 0 ; right < n ; right++){
            prod = prod * nums[right];

            while(prod >= k){
                prod /= nums[left];
                left++;
            }

            count += right - left + 1;
        }
        return count;
    }
};