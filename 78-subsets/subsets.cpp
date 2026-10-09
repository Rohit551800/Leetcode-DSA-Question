class Solution {
public:
    vector<vector<int>>ans;
    void f(int ind , vector<int>&nums ,vector<int>&temp ){
        if(ind >= nums.size()){ ans.push_back(temp) ; return ;}
         
        temp.push_back(nums[ind]);
        f(ind+1 , nums , temp);

        temp.pop_back();
        f(ind+1 , nums , temp);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>temp;
        f(0 , nums , temp);
        return ans;
    }
};