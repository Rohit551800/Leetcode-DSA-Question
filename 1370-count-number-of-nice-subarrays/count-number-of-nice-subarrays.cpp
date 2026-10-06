class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]%2 == 0){
                nums[i] = 0;
            }
            else{
                nums[i] = 1;
            }
        }

        int pre = 0;
        int cnt = 0;
        unordered_map<int , int>mpp;
        mpp[0] = 1;
        for(int i=0;i<n;i++){
            pre += nums[i];
            int rem = pre - k;

            cnt += mpp[rem];
            mpp[pre]++;
        }
        return cnt;
    }
};