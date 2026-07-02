class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
         int n = prices.size();
        vector<vector<int>> ahead(2, vector<int>(k+1, 0));

        vector<vector<int>> curr(2, vector<int>(k+1, 0)); 
        for (int ind = n - 1; ind >= 0; ind--) {
            for (int buy = 0; buy <= 1; buy++) {
                for (int cap = k; cap >= 1; cap--) {
                    if (buy) {
                        int not_take = ahead[1][cap];
                        int take =
                            -prices[ind] + ahead[0][cap];

                        curr[buy][cap] = max(take, not_take);
                    } else {
                        int sell =
                            prices[ind] + ahead[1][cap-1];
                        int not_sell = ahead[0][cap];
                         curr[buy][cap] = max(sell, not_sell);
                    }

                    //ahead=curr;
                }
                ahead=curr;
            }
        }
        return ahead[1][k];
    }
};