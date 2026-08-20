class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        vector<int>arr1;
        vector<int>arr2;
        int n = nums.size();
        if(n == 1) return nums;

        arr1.push_back(nums[0]);
        arr2.push_back(nums[1]);

        int arr1Max = nums[0];
        int arr2Max = nums[1];

        for(int i=2;i<n;i++){
            if(arr1Max > arr2Max){
                arr1Max = nums[i];
                arr1.push_back(nums[i]);
            }
            else{
                arr2Max = nums[i];
                arr2.push_back(nums[i]);
            }
        }

        for(int i= 0;i<arr2.size();i++){
            arr1.push_back(arr2[i]);
        }

        return arr1;
    }
};