class Solution {
public:
    string replaceDigits(string s) {
        int n = s.size();
        //Bruteforce

        // string ans = "";
        // for(int i=0;i<n;i++){
        //     if(isalpha(s[i])){
        //         ans.push_back(s[i]);
        //     }
        //     else{
        //         ans.push_back(ans[i-1] + s[i]-'0');
        //     }
        // }
        // return ans;

        //Optimal

        for(int i=0;i<n;i++){
            if(!isalpha(s[i])){
                s[i] = s[i-1] + s[i]-'0';
            }
        }
        return s;
    }
};