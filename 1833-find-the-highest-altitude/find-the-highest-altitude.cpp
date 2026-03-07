class Solution {
    public :
    int largestAltitude(vector<int> &gain ) {
        int rider = 0;
        int max = 0;
        for(int i=0;i<gain.size();i++){
            rider += gain[i];        
            if(rider > max){
                max=rider;
            }
        }
        return max;
    }
};