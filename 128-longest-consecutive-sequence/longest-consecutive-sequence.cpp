class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
        int maxi = 1;
        int counter = 1;
        sort(nums.begin() , nums.end());

        for(int i=0;i<n-1;i++){
            if(nums[i] == nums[i+1]) continue;
            if(nums[i] + 1 == nums[i + 1]){
                counter++;
            }
            else counter = 1;
            maxi = max(maxi , counter);
        }
        return maxi;
    }
};