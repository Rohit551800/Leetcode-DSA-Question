class Solution {
public:
    void helper(int n , int m , vector<vector<int>>&matrix , int row , int col){
        for(int x = 0;x<m;x++){
            if(matrix[row][x] == 1e9 + 11){}
            else matrix[row][x] = 0;
        }
        for(int x = 0;x<n;x++){
            if(matrix[x][col] == 1e9 + 11){}
            else matrix[x][col] = 0;
        }
    }

    void setZeroes(vector<vector<int>>& matrix) {
        int row = matrix.size(); 
        int col = matrix[0].size(); 

        // for(int i=0;i<row;i++){
        //     for(int j=0;j<col;j++){
        //         if(matrix[i][j] == 0) matrix[i][j] = 1e9 + 11;
        //     }
        // }
        // for(int i=0;i<row;i++){
        //     for(int j=0;j<col;j++){
        //         if(matrix[i][j] == 1e9 + 11){
        //             helper(row , col , matrix , i , j);
        //             matrix[i][j] = 0;
        //         }
        //     }
        // }

        //Better Solution

        vector<int>rows(row , 0);
        vector<int>cols(col , 0);

        for(auto i=0;i<row;i++){
            for(auto j=0;j<col;j++){
                if(matrix[i][j] == 0){
                    rows[i] = 1;
                    cols[j] = 1;
                }
            }
        }

        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(rows[i] == 1 || cols[j] == 1){
                    matrix[i][j] = 0;
                }
            }
        }
    }
};