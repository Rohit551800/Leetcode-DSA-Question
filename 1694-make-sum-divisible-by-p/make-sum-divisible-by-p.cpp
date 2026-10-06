class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int n = nums.size();
        //total sum - p = target
        long long total = 0;
        for(auto it : nums) total += it;

        int target = total % p;
        if(target == 0) return 0;
        int pre = 0;
        int ans = n;
        unordered_map<int , int>mpp;
        mpp[0] = -1;

        for(int i=0;i<n;i++){
            pre = (pre + nums[i]) % p;
            int rem = (pre - target + p) % p;

            if(mpp.count(rem)){
                ans = min(ans , i - mpp[rem]);
            }
            mpp[pre] = i;
        }
        return ans == n ? -1 : ans;
    }
};