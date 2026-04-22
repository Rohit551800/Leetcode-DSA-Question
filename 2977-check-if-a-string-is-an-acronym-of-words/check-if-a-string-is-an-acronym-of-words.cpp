class Solution {
public:
    bool isAcronym(vector<string>& words, string s) {
        int n = words.size();
        string arc = "";
        for(int i=0;i<n;i++){
            arc += words[i][0];
        }
        if(arc == s) return true;
        return false;
    }
};