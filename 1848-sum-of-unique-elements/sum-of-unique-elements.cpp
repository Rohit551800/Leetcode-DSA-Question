class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        //Bruteforce Solution
        int n = nums.size();
        int sum = 0;
        for(int i=0;i<n;i++){
            bool dupli = false;
            for(int j=0;j<n;j++){
                if(i == j)continue;
                if(nums[i] == nums[j]){
                    dupli = true;
                }
            }
            if(!dupli) sum += nums[i];
        }
        return sum;
        //Better Solution Solution
        // unordered_map<int , int>mpp;
        // for(auto it : nums){
        //     mpp[it]++;
        // }
        // int sum = 0;
        // for(auto it : mpp){
        //     if(it.second == 1) sum += it.first;
        // }
        // return sum;
        // Tc = O(n) SC O(n)

    }
};