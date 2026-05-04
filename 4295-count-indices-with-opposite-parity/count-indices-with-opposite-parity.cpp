class Solution {
public:
    vector<int> countOppositeParity(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans;
        for(int i=0;i<n;i++){
            int count = 0;
            if(nums[i] % 2 == 1){
                for(int j=i+1;j<n;j++){
                    if(nums[j] % 2 == 0) count++;
                }
            }
            else{
                for(int j=i+1;j<n;j++){
                    if(nums[j] % 2==1) count++;
                }
            }
            ans.push_back(count);
        }
        return ans;
    }
};