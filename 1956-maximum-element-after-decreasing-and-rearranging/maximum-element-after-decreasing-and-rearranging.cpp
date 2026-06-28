class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin() , nums.end());

        if(nums[0] != 1)nums[0] = 1;
        int maxi = nums[0];

        for(int i=1;i<n;i++){
            if(abs(nums[i] - nums[i-1]) <= 1){
                maxi = nums[i];
            }
            else{
                nums[i] = maxi+1;
                maxi = nums[i];
            }
        }
        return maxi;
    }
};