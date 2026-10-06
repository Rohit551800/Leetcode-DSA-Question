class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int pre = 0;
        unordered_map<int , int>mpp;
        mpp[0] = -1;

        for(int i=0;i<n;i++){
            pre += nums[i];
            int rem = pre % k ;
            if(mpp.count(rem)){
                if(i - mpp[rem] >=2){
                    return true;
                }
            }
            if(!mpp.count(rem)){
                mpp[rem] = i;
            }
        }
        return false;
    }
};