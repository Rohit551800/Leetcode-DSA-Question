class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        for(int i=0;i<n;i++){
            if(nums[i] == 0){
                nums[i] = -1;
            }
        }
        int prefix = 0;
        int ans = 0;
        unordered_map<int , int>mpp;
        mpp[0] = -1;

        for(int i=0;i<n;i++){
            prefix += nums[i];
            int rem = prefix - 0;

            if(mpp.count(rem)){
                ans = max(ans , i - mpp[rem]);
            }
            if(!mpp.count(prefix)){
                mpp[prefix] = i;
            }
        }
        return ans;
    }
};