class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int n = tokens.size();
        stack<int>st;
        for(int i=0;i<n;i++){
            if(tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/"){
                int n1 = st.top();st.pop();
                int n2 = st.top();st.pop();

                if(tokens[i] == "+") st.push(n1 + n2);
                else if(tokens[i] == "-") st.push(n2 - n1);
                else if(tokens[i] == "*") st.push(n1 * n2);
                else st.push(n2 / n1);
            }
            else{
                st.push(stoi(tokens[i]));
            }
        }
        return st.top();
    }
};