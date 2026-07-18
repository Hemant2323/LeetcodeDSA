class Solution {
public:
    bool ispalindrome(int i, int j, string& s) {

        while (i < j) {
            if (s[i] == s[j]) {
                i++;
                j--;
            } else {
                return false;
            }
        }
        return true;
    }
    int f(int i, string& s, vector<int>& dp) {
        if (i == s.size()) {
            return 0;
        }
        if (dp[i] != -1) {
            return dp[i];
        }

        int mincost = 1e9;
        for (int j = i; j < s.size(); j++) {

            if (ispalindrome(i, j, s)) {
                int cost = 1 + f(j + 1, s, dp);
                mincost = min(mincost, cost);
            }
        }
        return dp[i] = mincost;
    }
    int minCut(string s) {
        int n = s.size();
        vector<int> dp(n + 1, 0);
        // return f(0,s,dp)-1;
       
        for (int i = n - 1; i >= 0; i--) {
             int mincost = 1e9;
            for (int j = i; j < s.size(); j++) {

                if (ispalindrome(i, j, s)) {
                    int cost = 1 + dp[j + 1];
                    mincost = min(mincost, cost);
                }
            }
            dp[i]=mincost;
        }
        return dp[0]-1;
    }
};