class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        vector<int>result;
        for(auto i : arr2){
            for(int j=0;j<arr1.size();j++){
                if(i == arr1[j]){
                    result.push_back(i);
                    arr1[j] = -1;
                }
            }
        }
        sort(arr1.begin() , arr1.end());
        for(auto it : arr1){
            if(it != -1){
                result.push_back(it);
            }
        }
        return result;
    }
};