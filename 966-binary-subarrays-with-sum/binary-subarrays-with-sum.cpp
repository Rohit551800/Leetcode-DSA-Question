class Solution {
public:
    int funcAtMost(vector<int>&nums , int goal){
        int n =nums.size();
        if(goal < 0) return 0;
        int right = 0 , left = 0 , count = 0 , sum = 0;

        while(right < n){
            sum += nums[right];
            while(sum > goal){
                sum -= nums[left];
                left++;
            }
            count += (right -left + 1);
            right++;
        }
        return count;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        //Bruteforce Solution


        // int n = nums.size();
        // int count  = 0;
        // for(int i=0;i<n;i++){
        //     int sum = 0 ;
        //     for(int j=i;j<n;j++){
        //         sum += nums[j];
        //         if(sum == goal)  count++;
        //     }
        // }
        // return count;

        //Optimal Solution
        return funcAtMost(nums , goal) - funcAtMost(nums , goal -1);
    }
};