class Solution {
public:
    int checkMaxInRow(vector<vector<int>>& mat , int mid){
        int n = mat.size();
        int maxi = INT_MIN , index = - 1;

        for(int i=0;i<n;i++){
            if(mat[i][mid] >maxi){
                maxi = mat[i][mid];
                index = i;
            }
        }
        return index;
    }
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int cols = mat[0].size();

        int low = 0 , high = cols - 1;

        while(low <= high){
            int mid = low + (high - low)/2;

            int index = checkMaxInRow(mat , mid);

            int left = mid - 1 >= 0 ? mat[index][mid-1] : -1;
            int right = mid + 1 < cols ? mat[index][mid + 1] : -1;

            if(mat[index][mid] > left && mat[index][mid] > right) return {index , mid};
            else if(mat[index][mid] > left) low = mid + 1;
            else high = mid - 1;
        }
        return {-1 , -1};
    }
};