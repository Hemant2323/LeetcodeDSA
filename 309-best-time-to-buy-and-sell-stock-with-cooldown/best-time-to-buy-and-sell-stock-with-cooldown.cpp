class Solution {
public:
    int f(int ind, int buy, vector<int>& prices, int n,
          vector<vector<int>>& dp) {
        if (ind >= n) {
            return 0;
        }
        if (dp[ind][buy] != -1) {
            return dp[ind][buy];
        }
        if (buy) {
            int not_take = f(ind + 1, 1, prices, n, dp);
            int take = -prices[ind] + f(ind + 1, 0, prices, n, dp);

            return dp[ind][buy] = max(take, not_take);
        } else {
            int sell = prices[ind] + f(ind + 2, 1, prices, n, dp);
            int not_sell = f(ind + 1, 0, prices, n, dp);
            return dp[ind][buy] = max(sell, not_sell);
        }
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        //vector<vector<int>> dp(n + 1, vector<int>(2, -1));

        // return f(0,1,prices,n,dp);
        vector<int> ahead2(2,0);
        vector<int> ahead1(2,0);
        vector<int> curr(2,0);

        for (int ind = n - 1; ind >= 0; ind--) {

            for (int buy = 0; buy <= 1; buy++) {

                if (buy) {

                    int take = -prices[ind] + ahead1[0];
                    int notTake = ahead1[1];

                    curr[buy] = max(take, notTake);

                } else {

                    int sell = prices[ind] + ahead2[1];
                    int notSell = ahead1[0];

                    curr[buy] = max(sell, notSell);
                }
                ahead2=ahead1;
                ahead1=curr;
            }
        }

        return ahead1[1];
    }
};