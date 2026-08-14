class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int>st;
        int n = nums.size();
        vector<int>nge(nums.size());
        for(int i=2*n-1;i>=0;i--){
            int index = i % n;
            while(!st.empty() && st.top() <= nums[index]){
                st.pop();
            }
            if(i < n){
                if(st.empty()){
                    nge[index] = -1;
                }
                else{
                nge[index] = st.top();
                }
            }
            st.push(nums[index]);
        }
        return nge;



        // Practice --Bruteforce Solution


        // int n = nums.size();
        // vector<int>nge(n , -1);

        // for(int i=0;i<n;i++){
        //     for(int j=i+1;j<i+n;j++){
        //         int index = j%n;
        //         if(nums[i] < nums[index]){
        //             nge[i] = nums[index];
        //             break;
        //         }
        //     }
        // }
        // return nge;
    }
};