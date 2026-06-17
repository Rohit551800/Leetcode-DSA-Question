class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        // vector<int>ans;
        // int n = nums.size();
        // unordered_map<int , int>mpp;
        // for(auto it : nums){
        //     mpp[it]++;
        // }
        // for(auto it : mpp){
        //     if(it.second > 1)ans.push_back(it.first);
        // }
        // return ans;

        vector<int>ans;
        unordered_map<int , int>mpp;
        for(auto it : nums){
            if(mpp.find(it) != mpp.end()){
                ans.push_back(it);
            }
            else{
                mpp[it] = 1;
            }
        }
        return ans;
    }
};