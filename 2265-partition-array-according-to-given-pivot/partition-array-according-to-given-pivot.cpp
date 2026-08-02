class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n = nums.size();
        vector<int>ans(n);

        int lp = 0 , ep = 0 , gp = 0;
        for(auto it : nums){
            if(it < pivot) lp++;
            else if(it == pivot) ep++;
            else gp++;
        }
        // cout<<lp<<ep<<gp;
        int i = 0 , j = lp  , k = lp+ep;

        for(int m=0;m<n;m++){
            if(nums[m] < pivot){
                ans[i++] = nums[m];
            }
            else if(nums[m] == pivot){
                ans[j++] = nums[m];
            }
            else{
                ans[k++] = nums[m];
            }
        }
        return ans;
    }
};