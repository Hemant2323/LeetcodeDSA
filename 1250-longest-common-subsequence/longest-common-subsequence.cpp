class Solution {
public:
    int solve(int i, int j, string& text1, string& text2,
              vector<vector<int>>& dp) {

        if (i == text1.size() || j == text2.size()) {

            return 0;
        }
        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        if (text1[i] == text2[j]) {
            return 1 + solve(i + 1, j + 1, text1, text2, dp);
        }
        return dp[i][j] = max(solve(i, j + 1, text1, text2, dp),
                              solve(i + 1, j, text1, text2, dp));
    }

    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        //vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        // return solve(0,0,text1,text2,dp);

        vector<int> curr(m+1,0),ahead(m+1,0);

        for (int i = n-1; i >=0; i--) {
            for (int j = m-1; j >=0; j--) {
                if (text1[i] == text2[j]) {
                    curr[j]= 1 + ahead[j+1];
                }
                else{
                    curr[j] = max(curr[j+1], ahead[j]);
                }
                 
            }
            ahead=curr;
        }
        return ahead[0];
    }
};