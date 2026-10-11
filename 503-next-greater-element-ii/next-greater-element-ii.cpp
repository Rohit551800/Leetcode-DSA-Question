class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        stack<int>st;
        vector<int>ans(n , 0);
        for (int i = 2 * n - 1; i >= 0; i--) {
            int idx = i % n;
            while(!st.empty() && st.top() <= nums[idx]){
                st.pop();
            }
            ans[idx] = st.empty() ? -1 : st.top();
            st.push(nums[idx]);
        }
        return ans;
    }
};