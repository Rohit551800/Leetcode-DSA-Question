class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int>ans;
        unordered_map<int , int> mpp;

        for(int i=0;i<n;i++){
            int rem = target - nums[i];
            if(mpp.find(rem) != mpp.end()){
                ans.push_back(mpp[rem]);
                ans.push_back(i);

                return ans;
            }
            mpp[nums[i]] = i;
        }
        return ans;
    }
};