class Solution {
public:
    int minimumCost(vector<int>& cost) {
        int sum = 0;
        int i = 0;
        int n = cost.size();
        sort(cost.begin() , cost.end() , greater<int>());
        while(i < n){
            if((i + 1) % 3 != 0) {
                sum += cost[i];
            }
            i++;
        }
        return sum;
    }
};