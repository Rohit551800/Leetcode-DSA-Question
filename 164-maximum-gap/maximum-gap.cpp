class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin() , nums.end());
        int maxi = 0;
        if(n == 1) return maxi;

        for(int i=1;i<n;i++){
            maxi = max(maxi , nums[i] - nums[i-1]);
        }
        return maxi;
    }
};