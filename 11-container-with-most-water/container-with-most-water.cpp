class Solution {
public:
    int maxArea(vector<int>& height) {
        int i=0 , j = height.size()-1;
        int totalWater = 0 , maxi = 0;
        while(i<j){
            int ht = min(height[i] , height[j]);
            int bd = j-i;

            totalWater = ht * bd;
            maxi = max(totalWater , maxi);

            if(height[i] < height[j]) i++;
            else j--;
        }
    return maxi;
    }
};