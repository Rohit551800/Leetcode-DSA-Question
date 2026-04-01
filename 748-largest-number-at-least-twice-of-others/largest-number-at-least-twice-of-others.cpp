class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int index = -1;int maxi = -1;
        for(int i=0;i<nums.size();i++){
            if(nums[i] > maxi){
                maxi = nums[i];
                index = i;
            }
        }
        sort(nums.begin() ,nums.end());
        if(nums[(nums.size() - 2)] * 2 > nums[nums.size() - 1]) return -1;
        return index;
    }
};