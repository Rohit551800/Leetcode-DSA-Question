class Solution {
public:
    int calPoints(vector<string>& op) {
        int n = op.size();
        stack<int>st;

        for(int i=0;i<n;i++){
            if(op[i] == "+"){
                if(st.size() > 1){
                    int elem1 = st.top();
                    st.pop();
                    int elem2 = st.top();
                    st.push(elem1);

                    st.push(elem1 + elem2);
                }
            }
            else if(op[i] == "C"){
                if(!st.empty()){
                    st.pop();
                }
            }
            else if(op[i] == "D"){
                if(!st.empty()){
                    st.push(2* st.top());
                }
            }
            else{
                st.push(stoi(op[i]));
            }
        }

        int ans = 0;
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }
        return ans;
    }
};