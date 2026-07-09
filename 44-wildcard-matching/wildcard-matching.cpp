class Solution {
public:
    bool f(int i, int j, string& s, string& p, vector<vector<int>>& dp) {
        if (i < 0 && j < 0) {
            return true;
        }

        if (j >= 0 && i < 0) {
            for (int k = 0; k <= j; k++) {
                if (p[k] != '*') {
                    return false;
                }
            }
            return true;
        }
        if (i >= 0 && j < 0) {
            return false;
        }
        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        if (s[i] == p[j] || p[j] == '?') {
            return dp[i][j] = f(i - 1, j - 1, s, p, dp);
        }
        if (p[j] == '*') {
            return dp[i][j] = f(i - 1, j, s, p, dp) || f(i, j - 1, s, p, dp);
        }

        return false;
    }
    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();
       // vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, -1));
        // return f(i-1,j-1,s,p,dp);
        vector<bool> curr(m+1,false) , prev(m+1,false);

        prev[0]=true;
        

        for(int j=1;j<=m;j++){
            bool flag=true;

            for(int k=1;k<=j;k++){
                if(p[k-1]!='*'){
                    flag=false;
                    break;
                }

                
            }
           prev[j]=flag;
        }

        for (int i = 1; i <= n; i++) {
            curr[0]=false;
            for (int j = 1; j <= m; j++) {
                if (s[i-1] == p[j-1] || p[j-1] == '?') {
                     curr[j] = prev[j-1];
                }
                else if (p[j-1] == '*') {
                     curr[j] =
                               prev[j] || curr[j-1];
                }
                else{
                    curr[j]= false;
                }
            }

            prev=curr;
        }
        return prev[m];
    }
};