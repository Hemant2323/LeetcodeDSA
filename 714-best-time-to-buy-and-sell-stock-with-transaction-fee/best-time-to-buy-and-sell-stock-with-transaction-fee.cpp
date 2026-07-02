class Solution {
public:
    int f(int ind, int buy, vector<int>& prices, int n,
          vector<vector<int>>& dp,int fee) {
        if (ind == n) {
            return 0;
        }
        if (dp[ind][buy] != -1) {
            return dp[ind][buy];
        }
        if (buy) {
            int not_take = f(ind + 1, 1, prices, n, dp,fee);
            int take = -prices[ind] + f(ind + 1, 0, prices, n, dp,fee);

            return dp[ind][buy] = max(take, not_take);
        } else {
            int sell = prices[ind] + f(ind + 1, 1, prices, n, dp,fee)-fee;
            int not_sell = f(ind + 1, 0, prices, n, dp,fee);
            return dp[ind][buy] = max(sell, not_sell);
        }
    }
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
       // vector<vector<int>> dp(n + 1, vector<int>(2, -1));

        //  return f(0,1,prices,n,dp,fee);
        vector<int> ahead(2, 0);
        vector<int> curr(2, 0);

        for (int ind = n - 1; ind >= 0; ind--) {
            for (int buy = 0; buy <= 1; buy++) {
                if (buy) {

                    int not_take = ahead[1];
                    int take = -prices[ind] + ahead[0];
                    curr[buy] = max(take, not_take);

                } else {

                    int sell = prices[ind] + ahead[1]-fee;
                    int not_sell = ahead[0];
                    curr[buy] = max(sell, not_sell);
                }

                ahead=curr;
            }
        }
        return ahead[1];
    }
};