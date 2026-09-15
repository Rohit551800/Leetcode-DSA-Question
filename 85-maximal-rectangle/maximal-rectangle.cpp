class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> st;
        int maxArea = 0;
        for(int i=0;i<n;i++){
            while(!st.empty() && heights[st.top()] >= heights[i]){
                int elem = heights[st.top()];
                st.pop();
                int nsIndex = i;
                int psIndex = st.empty()? -1 : st.top();
                maxArea = max(maxArea , elem * (nsIndex - psIndex - 1));
            }
            st.push(i);
        }
        while(!st.empty()){
            int elem = heights[st.top()];
            st.pop();
            int nsIndex = n;
            int psIndex =st.empty() ? -1 : st.top();
            maxArea = max(maxArea , elem * (nsIndex - psIndex - 1));
        }
        return maxArea;
    }
    int maximalRectangle(vector<vector<char>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        int maxArea = 0;
        vector<int>height(m , 0);

        for(int i=0 ; i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j] == '1') height[j] += 1;
                else height[j] = 0;
            }
            int area = largestRectangleArea(height);
            maxArea = max (maxArea , area);
        }
        return maxArea;
    }
};