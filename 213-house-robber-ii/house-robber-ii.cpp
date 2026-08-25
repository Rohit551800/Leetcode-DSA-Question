class Solution {
public:
    int findAns1(vector<int>&nums){
        int prev2 = 0;
        int prev1 = nums[1];
        for(int i=2;i<nums.size();i++){
            int take = nums[i] + prev2;
            int not_take = 0 + prev1;

            int curr = max(take , not_take);

            prev2 = prev1;
            prev1 = curr;
        }

        return prev1;
    }
    int findAns2(vector<int>&nums){
        int prev2 = 0;
        int prev1 = nums[0];
        for(int i=1;i<nums.size()-1;i++){
            int take = nums[i] + prev2;
            int not_take = 0 + prev1;

            int curr = max(take , not_take);

            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        int ans1 = findAns1(nums);
        int ans2 = findAns2(nums);

        return max(ans1 , ans2);
    }
};