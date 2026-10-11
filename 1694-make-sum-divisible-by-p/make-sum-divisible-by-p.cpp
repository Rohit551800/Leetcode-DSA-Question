class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int n = nums.size();
        int total = 0;
        for(int x : nums){
            total = (total + x) % p;
        }
        int target = total % p;

        if(target == 0) return 0;
        int prefix = 0;
        int minLen = INT_MAX;
        unordered_map<int , int>mpp;
        mpp[0] = -1;

        for(int i=0;i<n;i++){
            prefix = (prefix + nums[i]) % p;
            int rem = (prefix - target + p) % p;
            if(mpp.count(rem)){
                minLen = min(minLen , i-mpp[rem]);
            }
            mpp[prefix] = i;
        }
        return minLen == INT_MAX || minLen == n ? -1 : minLen;
    }
};