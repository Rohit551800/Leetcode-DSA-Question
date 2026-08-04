class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int low = *min_element(nums.begin() , nums.end());
        int high = *max_element(nums.begin() , nums.end());

        unordered_map<int,int>mpp;
        for(auto it : nums){
            mpp[it]++;
        }
        vector<int>ans;
        for(int i=low+1;i<high;i++){
            if(mpp.find(i) == mpp.end()){
                ans.push_back(i);
            }
        }
        return ans;
    }
};