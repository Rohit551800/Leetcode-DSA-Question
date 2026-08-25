class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_map<int , int>mpp;
        for(auto it : nums){
            mpp[it]++;
        }
        int x = k;
        while(true){
            if(mpp.find(k) != mpp.end()){
                k = k + x;
            }
            else return k;
        }
        return 0;
    }
};