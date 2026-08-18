class Solution {
public:
    string removeStars(string s) {
        stack<char>st;
        int n = s.size();
        int j = 0;

        while(j < n) {
            if(s[j] == '*'){}
            else break;
        }

        for(int i=j;i<n;i++){
            if(s[i] != '*') st.push(s[i]);
            else{
                if(!st.empty()){
                    st.pop();
                }
            }
        }
        string ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }

        reverse(ans.begin() , ans.end());
        return ans;
    }
};