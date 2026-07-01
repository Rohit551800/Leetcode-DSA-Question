class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& nums) {
        int n = nums.size();
        stack<int>st;
        vector<int>ans(n , 0);

        for(int i=0;i<n;i++){
            while(!st.empty() && nums[i] > nums[st.top()]) {
                ans[st.top()] = i - st.top();
                st.pop();
            }

            st.push(i);
        }
        return ans;
    }
};