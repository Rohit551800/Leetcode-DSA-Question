class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0] + 1;

        int preSum = 0 ;
        preSum = nums[0];

        for(auto i=0;i<n-1;i++){
            if(nums[i]+1 == nums[i+1]){
                preSum += nums[i+1];
            }
            else break;
        }

        unordered_set<int>seen(nums.begin() , nums.end());
        int ans = preSum;

        while(seen.count(ans)){
            ans++;
        }

        return ans;
    }
};