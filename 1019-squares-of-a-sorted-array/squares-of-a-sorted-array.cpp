class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {

        //Bruteforce solution


        // int n = nums.size();
        // for(int i=0;i<n;i++){
        //     nums[i] = nums[i] * nums[i];
        // }
        // sort(nums.begin() , nums.end());
        // return nums;


        //Optimal Solution

        int n = nums.size();
        vector<int>ans;
        vector<int>a;
        vector<int>b;

        for(int i=0;i<n;i++){
            if(nums[i] < 0) a.push_back(nums[i]);
            else break;
        }
        for(int i=0;i<n;i++){
            if(nums[i] >= 0) b.push_back(nums[i]);
        }


        if(a.size() == 0){
            for(int i=0;i<n;i++){
                b[i] = b[i] * b[i];
            }
            return b;
        }
        else if(b.size() ==0){
            for(int i=0;i<n;i++){
                a[i] = a[i] * a[i];
            }
            reverse(a.begin() , a.end());
            return a;
        }


        else {
            for(int i=0;i<a.size();i++){
                a[i] = a[i] * a[i];
            }
            reverse(a.begin() , a.end());
            for(int i=0;i<b.size();i++){
                b[i] = b[i] * b[i];
            }
            int i = 0 , j = 0;
            while(i<a.size() && j<b.size()){
                if(a[i] >= b[j]){
                    ans.push_back(b[j]);
                    j++;
                }
                else{
                    ans.push_back(a[i]);
                    i++;
                }
            }
            if(i==a.size() && j < b.size()){
                while(j < b.size()){
                    ans.push_back(b[j]);
                    j++;
                }
            }
            else if(j == b.size() && i <a.size()){
                while(i < a.size()){
                    ans.push_back(a[i]);
                    i++;
                }
            }
        }
        return ans;
    }
};