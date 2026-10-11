class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int prefix = 0;
        int maxLen = 0;
        unordered_map<int , int>mpp;
        mpp[0] = -1;
        for(int i=0;i<n;i++){
            prefix += nums[i];
            int rem = prefix % k;
            if(mpp.find(rem) != mpp.end()){
                maxLen = max(maxLen , i - mpp[rem]);
                if(maxLen >= 2) return true;
            }
            if(mpp.find(rem) == mpp.end()) mpp[rem] = i;
        }
        return false;
    }
};