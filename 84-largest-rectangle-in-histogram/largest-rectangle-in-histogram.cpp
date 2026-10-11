class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int>st;
        int maxi = 0;

        for(int i=0;i<=n;i++){
            int curr = i == n ? 0 : heights[i];
            while(!st.empty() && heights[st.top()] > curr){
                int h = heights[st.top()];
                st.pop();

                int w = st.empty() ? i : i - st.top() - 1;

                maxi = max(maxi , h * w);
            }
            st.push(i);
        }
        return maxi;
    }
};