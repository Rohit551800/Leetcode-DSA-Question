class Solution {
public:
    bool searchMatrix(vector<vector<int>>& nums, int target) {
        int n = nums.size();
        int m = nums[0].size();

        int row = n-1 , col = 0;

        while(row >= 0 && col < m){
            if(nums[row][col] == target) return true;
            else if(nums[row][col] < target) col++;
            else row--;
        }
        return false;
    }
};