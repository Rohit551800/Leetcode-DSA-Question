class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        int index = 0 ;
        int count = 0;

        for(int i=0;i<n;i++){
            int rowC = 0;
            for(int j=0;j<m;j++){
                if(mat[i][j] == 1) rowC++;
            }
            if(rowC > count){
                count = rowC;
                index = i;
            }
        }
        return {index , count};
    }
};