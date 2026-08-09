class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        for(auto it : s){
            if(it == '(' || it == '[' || it == '{') st.push(it);
            else if(st.empty()) return false;
            else{
                char c = st.top();
                st.pop();
                if(it == ')'  && c == '(' ||
                it == ']' && c == '[' || 
                it == '}' && c == '{'){

                }
                else return false;
            }
        }
        return st.empty();
    }
};