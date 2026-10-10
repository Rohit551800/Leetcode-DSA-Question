class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int lower = -1;
        int upper = -1;
        int n = nums.size();

        lower = lower_bound(nums.begin() , nums.end() , target) - nums.begin();
        upper = upper_bound(nums.begin() , nums.end() , target) - nums.begin();

        if(lower == n || nums[lower] != target) return {-1 , -1};
        return {lower , upper - 1};
    }
};