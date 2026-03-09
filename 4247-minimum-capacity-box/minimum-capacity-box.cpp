class Solution {
public:
    int minimumIndex(vector<int>& capacity, int itemSize) {
        int miniIndex = -1;
        int requiredBox = INT_MAX;
        for(int i=0;i<capacity.size();i++){
            if(capacity[i] >= itemSize && requiredBox > capacity[i]){
                requiredBox = min(requiredBox , capacity[i]);
                miniIndex = i;
            }
        }
        return miniIndex;
    }
};