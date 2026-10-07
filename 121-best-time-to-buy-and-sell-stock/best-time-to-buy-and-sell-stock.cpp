class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = prices[0];
        int ans = 0;

        for (int i = 1; i < prices.size(); i++) {

            minPrice = min(minPrice, prices[i]);

            int profit = prices[i] - minPrice;

            ans = max(ans, profit);
        }

        return ans;
    }
};