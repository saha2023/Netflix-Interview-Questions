class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int sell = -1e9;
        int buy = 1e9;
        int profit = 0;
        for(int i=0;i<n;i++){
            sell = prices[i];
            buy = min(buy, prices[i]);
            profit = max(profit, sell-buy);
        }
        return profit;
    }
};