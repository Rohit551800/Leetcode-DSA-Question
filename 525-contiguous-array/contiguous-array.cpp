class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        for(int i=0;i<n;i++){
            if(nums[i] == 0) nums[i] = -1;
        }

        int prefix = 0;
        int maxLen = 0;
        unordered_map <int , int>mpp;
        mpp[0] = -1;

        for(int i=0;i<n;i++){
            prefix += nums[i];
            int rem = prefix - 0;
            if(mpp.find(rem) != mpp.end()){
                maxLen = max(maxLen , i - mpp[rem]);
            }
            if(mpp.find(prefix) == mpp.end()){
                mpp[prefix] = i;
            }
        }
        return maxLen;
    }
};