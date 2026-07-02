class Solution {
public:
    int f(int ind, int buy, vector<int>& prices, int n,
          vector<vector<vector<int>>>& dp, int cap) {
        if (ind == n) {
            return 0;
        }
        if (cap == 0) {
            return 0;
        }
        if (dp[ind][buy][cap] != -1) {
            return dp[ind][buy][cap];
        }
        if (buy) {
            int not_take = f(ind + 1, 1, prices, n, dp, cap);
            int take = -prices[ind] + f(ind + 1, 0, prices, n, dp, cap);

            return dp[ind][buy][cap] = max(take, not_take);
        } else {
            int sell = prices[ind] + f(ind + 1, 1, prices, n, dp, cap - 1);
            int not_sell = f(ind + 1, 0, prices, n, dp, cap);
            return dp[ind][buy][cap] = max(sell, not_sell);
        }
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(
            n+1, vector<vector<int>>(2, vector<int>(3, -1)));
        // int cap = 2;
        // return f(0, 1, prices, n, dp, cap);
        dp[0][1][0]=0;
        dp[0][0][0]=0;

        for (int ind = n - 1; ind >= 0; ind--) {
            for (int buy = 0; buy <= 1; buy++) {
                for (int cap = 2; cap >= 1; cap--) {
                    if (buy) {
                        int not_take = dp[ind+1][1][cap];
                        int take =
                            -prices[ind] + dp[ind+1][0][cap];

                        dp[ind][buy][cap] = max(take, not_take);
                    } else {
                        int sell =
                            prices[ind] + dp[ind+1][1][cap-1];
                        int not_sell = dp[ind+1][0][cap];
                         dp[ind][buy][cap] = max(sell, not_sell);
                    }
                }
            }
        }
        return dp[0][1][2]+1;
    }
};