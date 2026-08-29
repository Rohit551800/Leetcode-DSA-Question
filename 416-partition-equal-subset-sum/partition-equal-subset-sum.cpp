class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int s = 0;
        for(auto it : nums){
            s+= it;
        }
        if(s%2 == 1) return false;
        int k = s/2;
        vector<int>prev(k+1 , 0) , curr(k+1 , 0);
        prev[0] = curr[0] = true;
        if(nums[0] <= k) prev[nums[0]] = true;

        for(int ind = 1;ind<n;ind++){
            for(int target = 1;target<=k;target++){
                bool not_take = prev[target];

                bool take = false;

                if(nums[ind] <= target){
                    take = prev[target - nums[ind]];
                }
                curr[target] = take || not_take;
            }
            prev = curr;
        }
        return prev[k];
    }
};