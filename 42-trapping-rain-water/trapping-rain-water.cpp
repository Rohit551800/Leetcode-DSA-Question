class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();

        int rMax = 0 , lMax = 0;
        int totalCount = 0;
        int i = 0 , j = n-1;

        while(i<=j){

            if(height[i] <= height[j]){
                if(height[i] <= lMax){
                    totalCount += lMax - height[i];
                }
                else{
                    lMax = height[i];
                }
                i++;
            }
            else{
                if(height[j] <= rMax){
                    totalCount += rMax - height[j];
                }
                else{
                    rMax = height[j];
                }
                j--;
            }
        }
        return totalCount;
    }
};