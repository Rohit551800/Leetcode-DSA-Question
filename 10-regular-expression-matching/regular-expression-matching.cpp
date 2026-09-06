class Solution {
public:
        bool f(int i , int j , string &s , string &t , vector<vector<int>>&dp){
        //BaseCase
        if(i<0 && j<0) return true;
        if(j<0) return false;
        if(i < 0){
            if(t[j] == '*') {
            return f(i, j - 2, s, t, dp); 
        }
        return false;
        }
        //Explore All paths
        if(dp[i][j] != -1) return dp[i][j];
        if(s[i] == t[j] || t[j] == '.')return dp[i][j] = f(i-1 , j-1 , s , t ,dp);
        else if(t[j] == '*'){
            bool one = f(i , j-2 , s , t , dp);
            bool more = false;
            if(t[j-1] == s[i] || t[j-1] == '.'){
                more = f(i-1 , j , s , t , dp);
            }
            return dp[i][j] = one || more;
        }
        else return dp[i][j] = false;
    }
    bool isMatch(string s, string t) {
        int n = s.size() , m = t.size();
        vector<vector<int>>dp(n , vector<int>(m , -1));
        return f(n-1 , m-1 ,s , t , dp);
        // Space Optimization

        vector<bool>prev(m+1 , false) , curr(m+1);

        //Base case
        prev[0] = true;

        for(int j = 1; j <= m; j++){
            if(t[j-1] == '*'){
                prev[j] = prev[j-1];
            }
        }
        // Explore all the paths

        for(int i=1;i<=n;i++){
            curr[0] = false;
            for(int j=1;j<=m;j++){
                if(s[i-1] == t[j-1] || t[j-1] == '.') curr[j] = prev[j-1];
                else if(t[j-1] == '*') curr[j] = curr[j-1]|| prev[j] ;
                else curr[j] = false;
            }
            prev = curr;
        }
        return prev[m];
    }
};