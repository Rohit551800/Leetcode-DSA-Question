class Solution {
public:
    int findMin(int i ,vector<int>nums){
        int mini = INT_MAX;
        for(int x = i;x<nums.size();x++){
            if(mini > nums[x]){
                mini = nums[x];
            }
        }
        return mini;
    }
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        // vector<int>premax;
        // vector<int>sufmin;
        int maxi = -1;
        int mini = INT_MAX;
        for(int i=0;i<n;i++){
            if(nums[i] > maxi){
                maxi = nums[i];
            }
            int mini = findMin(i , nums);
            if((maxi - mini) <= k) return i;            
        }
        return -1;
    }
};