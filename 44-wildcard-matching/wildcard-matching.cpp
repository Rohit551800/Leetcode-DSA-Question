class Solution {
public:
    bool f(int i , int j , string &s , string &t , vector<vector<int>>&dp){
        //BaseCase
        if(i<0){
            while(j >= 0){
                if(t[j] != '*') return false;
                j--;
            }
        }
        if(i<0 && j<0) return true;
        if(j<0) return false;
        //Explore All paths
        if(dp[i][j] != -1) return dp[i][j];
        if(s[i] == t[j] || t[j] == '?')return dp[i][j] = f(i-1 , j-1 , s , t ,dp);
        else if(t[j] == '*')return dp[i][j] = f(i,j-1 ,s , t , dp)||f(i-1, j, s, t,dp);
        else return dp[i][j] = false;
    }
    bool isMatch(string s, string t) {
        int n = s.size() , m = t.size();
        vector<vector<int>>dp(n , vector<int>(m , -1));
        return f(n-1 , m-1 ,s , t , dp);
    }
};