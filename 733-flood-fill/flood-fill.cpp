class Solution {
public:
    void dfs(vector<vector<int>>&mat , int iniColor ,int color , vector<int>vr, vector<int>vc , int sr , int sc){

        mat[sr][sc] = color;
        int n = mat.size();
        int m = mat[0].size();

        for(int i=0;i<4;i++){
            int row = sr + vr[i] ;
            int col = sc + vc[i];

            if(row < 0 || row >= n) continue;
            if(col < 0 || col >= m) continue;

            if(mat[row][col] != color && mat[row][col] == iniColor){
                dfs(mat , iniColor , color ,vr , vc , row , col);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        vector<vector<int>>mat = image;

        vector<int>vr  = {-1 , 1 , 0 , 0 };
        vector<int>vc  = {0 , 0 , 1 , -1 };

        int iniColor = mat[sr][sc];

        dfs(mat , iniColor , color , vr ,vc , sr , sc);
        return mat;
    }
};