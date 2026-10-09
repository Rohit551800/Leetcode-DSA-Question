class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        // int mini = INT_MAX;
        // int n = nums.size();
        // for(int i=0;i<n;i++){
        //     int sum = 0;
        //     for(int j=i;j<n;j++){
        //         sum += nums[j];
        //         if(sum >= target){
        //             mini = min(mini , j-i+1);
        //         }
        //     }
        // }
        // if(mini == INT_MAX) return 0;
        // return mini;
        
        int n = nums.size();
        int left = 0 , right = 0;
        int mini = INT_MAX;
        int sum = 0;
        while(right < n){
            sum += nums[right];
            while(sum >= target){
                mini = min(mini , right - left + 1);
                sum -= nums[left];
                left++;
            }
            right++;
        }
        return mini == INT_MAX ? 0 : mini ;
    }
};