class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int n = nums.size();
        if(n < 2) return -1;
        int dist = INT_MAX;
        for(int i=0;i<n;i++){
            int ittDist = 0;
            for(int j=i+1;j<n;j++){
                for(int k=j+1;k<n;k++){
                    if(nums[i] == nums[j] && nums[j] == nums[k]){
                        ittDist = abs(i - j) + abs(j-k) + abs(k-i);
                        dist = min(dist , ittDist);
                    }
                }
            }
        }
        if(dist != INT_MAX)return dist;
        return -1;
    }
};