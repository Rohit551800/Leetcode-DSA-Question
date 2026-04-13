class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        int n = nums.size();
        int ans = INT_MAX;
        for(int i=0;i<n;i++){
            if(nums[i] == target){
                int ans1 =abs(i - start);

                if(ans1 < ans){
                    ans = ans1;
                }
            }
        }
        return ans;
    }
};