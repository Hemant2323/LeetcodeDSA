class Solution {
public:
    int f(int ind, int k, vector<int>& arr, vector<int>& dp) {
        if (ind == arr.size()) {
            return 0;
        }
        if (dp[ind] != -1) {
            return dp[ind];
        }
        int len = 0;
        int maxi = INT_MIN;
        int maxsum = 0;

        for (int i = ind; i < min((int)arr.size(), ind + k); i++) {
            maxi = max(maxi, arr[i]);
            len++;
            int sum = len * maxi + f(i + 1, k, arr, dp);
            maxsum = max(maxsum, sum);
        }
        return dp[ind] = maxsum;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size() - 1;
        vector<int> dp(n + 2, 0);

        //  return f(0,k,arr,dp);
        int len = 0;
        int maxi = INT_MIN;
        int maxsum = 0;

        for (int ind = n; ind >= 0; ind--) {
            int len = 0;
            int maxi = INT_MIN;
            int maxsum = 0;
            for (int i = ind; i < min((int)arr.size(), ind + k); i++) {
                maxi = max(maxi, arr[i]);
                len++;
                int sum = len * maxi + dp[i + 1];
                maxsum = max(maxsum, sum);
            }
            dp[ind] = maxsum;
        }
        return dp[0];
    }
};