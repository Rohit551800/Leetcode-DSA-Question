class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {
        int n = boxGrid.size();
        int m = boxGrid[0].size();
        vector<vector<char>> ans(m , vector<char>(n));

        //Moving values to the right
        for(int i=0;i<n;i++){
            int k = m-1;
            for(int j=m-1;j>=0;j--){
                if(boxGrid[i][j] == '*'){
                    k = j-1;
                }

                if(boxGrid[i][j] == '#'){
                    swap(boxGrid[i][j] , boxGrid[i][k]);
                    k--;
                }
            }
        }
        
        
        // Rotating the matrix by 90deg
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                ans[j][n-1-i] = boxGrid[i][j];
            }
        }
        return ans;
    }
};