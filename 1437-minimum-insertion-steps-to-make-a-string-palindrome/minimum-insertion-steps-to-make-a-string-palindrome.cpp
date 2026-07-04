class Solution {
public:
    int f(int i,int j,string &s,vector<vector<int>> &dp){
        if(i>=j){
            return 0;
        }
        if(s[i]==s[j]){
            return f(i+1,j-1,s,dp);
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        
            return dp[i][j]= 1+min(f(i+1,j,s,dp),f(i,j-1,s,dp));
        
    }
    int minInsertions(string s) {
        int x=s.size();
        vector<vector<int>>dp(x+1,vector<int>(x+1,-1));
        return f(0,s.size()-1,s,dp);
        // int x = s.size();

        // int i = 0;
        // int j = s.size() - 1;

        // while (i < j) {

        //     if (s[i] == s[j]) {
        //         i++;
        //         j--;
        //     } else {
        //         s.insert(s.begin() + j + 1, s[i]);
        //         i++;
        //         // j stays at the same index
        //     }
        // }

        // int count = s.size() - x;

        // if (i == j) {
        //     return count;
        // }

        // if (s[i] != s[j]) {
        //     count++;
        // }

        // return count;


    }
};