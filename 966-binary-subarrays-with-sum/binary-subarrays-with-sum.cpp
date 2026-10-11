class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size();
        int prefix = 0;
        int count = 0;
        unordered_map<int , int>mpp;
        mpp[0] = 1;
        
        for(int i=0;i<n;i++){
            prefix += nums[i];
            int rem = prefix - goal;
            if(mpp.find(rem) != mpp.end()){
                count += mpp[rem];
            }
            mpp[prefix]++;
        }
        return count ;
    }
};