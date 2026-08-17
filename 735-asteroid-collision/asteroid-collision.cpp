class Solution {
public:
    vector<int> asteroidCollision(vector<int>& nums) {
        stack<int>st;
        vector<int>ans;
        int n = nums.size();
        int x = -1;
        int j = 0;
        while( j < n ){
            if(nums[j] < 0){
                st.push(nums[j++]);
            }
            else break;
        }
        for(int i=j;i<n;i++){
            if(nums[i] > 0){
                st.push(nums[i]);
            }
            else{
                x = -1;
                while(!st.empty() && st.top() > 0){
                    if(st.top() <= (-1 * nums[i])){
                        x = st.top();
                        st.pop();

                        if (x == (-1 * nums[i])) {
                            break;
                        }
                    }
                    else { 
                        break; 
                    }
                }
                if ((st.empty() || st.top() < 0) && x < (-1 * nums[i])) { 
                    st.push(nums[i]); 
                } 
            }
        }

        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin() , ans.end());
        return ans;
    }
};