class Solution {
public:
    int findRightBoundary(vector<int>nums){
        int rightIndex = -1;
        int maxi = nums[0];
        for(int i=0;i<nums.size();i++){
            if(nums[i] < maxi){
                rightIndex = i;
            }
            else{
                maxi = nums[i];
            }
        }return rightIndex;
    }
    int findLeftBoundary(vector<int>nums){
        int n = nums.size();
        int leftIndex = -1;
        int mini = nums[n-1];
        for(int i = n-1;i>=0;i--){
            if(nums[i] > mini){
                leftIndex = i;
            }
            else{
                mini = nums[i];
            }
        }return leftIndex;
    }
    int findUnsortedSubarray(vector<int>& nums) {
        int left = findLeftBoundary(nums);
        int right = findRightBoundary(nums);

        if(left == -1) return 0;
        return right - left + 1;
    }
};