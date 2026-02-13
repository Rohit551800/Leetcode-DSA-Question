class Solution {
public:
    char findTheDifference(string s, string t) {
        int n = s.size();
        int m = t.size();
        unordered_map<int , int> mpp;
        for(int i=0;i<n;i++){
            mpp[s[i]]++;
        }
        int j = 0;
        while(j < m){
            if(mpp.find(t[j]) != mpp.end()){
                if(mpp[t[j]] == 0) return t[j];
                mpp[t[j]]--;
                j++;
            }
            else{
                break;
            }
        }
        return t[j];
    }
};