class Solution {
public:
    int f(int i,int j,string &s,string &t,vector<vector<long long>>&dp){

        if(j<0){
            return 1;
        }
        if(i<0){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        if(s[i]==t[j]){
           return dp[i][j]= f(i-1,j-1,s,t,dp)+f(i-1,j,s,t,dp);
        }
        else{
            return dp[i][j]= f(i-1,j,s,t,dp);
        }
    }
    int numDistinct(string s, string t) {
        int i=s.size();
        int j=t.size();
        vector<vector<long long>>dp(i,vector<long long>(j,-1));
        return f(i-1,j-1,s,t,dp);
    }
};