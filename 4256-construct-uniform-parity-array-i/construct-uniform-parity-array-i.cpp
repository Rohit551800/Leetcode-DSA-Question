class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        bool hasEven = false, hasOdd = false , allEven = false , allOdd = false;
        if(nums1.size() == 1) return true;
        for(auto it : nums1){
            if(it % 2 != 0){
                hasOdd = true;
                break;
            }
        }
        if(hasOdd == false) return true;
        for(auto it : nums1){
            if(it % 2 == 0){
                hasEven = true;
                break;
            }
        }
        if(hasEven == false) return true;
        for(int x : nums1){
            if(x % 2 == 0) hasEven = true;
            else hasOdd = true;
        }

        return hasEven && hasOdd;
    }
};