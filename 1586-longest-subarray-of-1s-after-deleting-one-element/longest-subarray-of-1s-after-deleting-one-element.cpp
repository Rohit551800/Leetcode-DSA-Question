class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int left = 0 , right = 0;
        int rm = 0;
        int maxi = INT_MIN;
        
        for(int i=0;i<n;i++){
            if(nums[i] == 0) rm++;
            while(rm > 1){
                if(nums[left] == 0) rm--;
                left++;
            }
            maxi = max(maxi , i - left + 1);
        }
        if(maxi == n) return maxi - 1;
        return rm == 0 ? maxi : maxi - 1;
    }
};