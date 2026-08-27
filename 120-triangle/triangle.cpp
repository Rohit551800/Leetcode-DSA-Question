class Solution {
public:
    int f(vector<vector<int>>&tri , int i , int j , vector<vector<int>>&dp){
        if(i == tri.size() -1) return tri[i][j];
        if(dp[i][j] != -1) return dp[i][j];
        int down = INT_MAX , rdiag = INT_MAX;

        down = f(tri , i+1 , j , dp);
        rdiag = f(tri , i+1 , j+1 , dp);

        return dp[i][j] = tri[i][j] + min(down ,rdiag);
    }
    int minimumTotal(vector<vector<int>>& tri) {
        // int n = tri.size();
        int n = tri.size();
        if(n == 1) return *min_element(tri[0].begin() , tri[0].end());
        // return f(tri , 0 , 0);

        //Apply Memoization
        // vector<vector<int>>dp(n , vector<int>(n , -1));
        // return f(tri , 0 , 0 , dp); //TLE

        //Tabulation

        // vector<vector<int>>dp(n , vector<int>(n , -1));
        // for(int i=0;i<n;i++){
        //     dp[n-1][i] = tri[n-1][i];
        // }

        // for(int i=n-2;i>=0;i--){
        //     for(int j=i;j>=0;j--){
        //         int down  = INT_MAX , rdown = INT_MAX;
        //         down = dp[i+1][j];
        //         rdown = dp[i+1][j+1];

        //         dp[i][j] = tri[i][j] + min(down , rdown);
        //     }
        // }
        // return dp[0][0];

        //Space Optimization

        vector<int>prev(n , -1);
        for(int i=0;i<n;i++){
            prev[i] = tri[n-1][i];
        }

        for(int i=n-2;i>=0;i--){
            vector<int>curr(n , 0);
            for(int j=i;j>=0;j--){
                int down = INT_MAX , rdown = INT_MAX;
                down = prev[j];
                rdown = prev[j+1];

                curr[j] = tri[i][j] + min(down , rdown);
            }

            prev= curr;
        }
        return prev[0];
    }
};