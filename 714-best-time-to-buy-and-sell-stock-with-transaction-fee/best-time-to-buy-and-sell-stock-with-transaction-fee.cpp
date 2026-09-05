class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<int>prev(2 , 0) , ahead(2 , 0);
        for(int ind = n-1 ; ind>= 0;ind--){
            for(int buy=0;buy<=1;buy++){
                int profit = 0;
                if(buy){
                    profit = max(-prices[ind] + prev[0], 0 + prev[1]);
                }
                else{
                    profit = max(prices[ind] - fee + prev[1], 0 + prev[0]);
                }
                ahead[buy] = profit;
            }
            prev = ahead;
        }
        return prev[1];
    }
};