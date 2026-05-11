class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int>ans;
        for(int i=0;i<nums.size();i++){
            int x = nums[i];
            vector<int>num;
            while(x){
                int last = x % 10;
                x = x / 10;
                num.push_back(last);
            }
            for(int i=num.size() -1;i>=0;i--){
                ans.push_back(num[i]);
            }
        }
        return ans;
    }
};