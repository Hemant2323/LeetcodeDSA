class Solution {
public:
    bool f(int i,int j, string &s, string &p,vector<vector<int>>&dp){
        if(i<0 && j<0){
            return true;
        }
        
        if(j>=0 && i<0){
            for(int k=0;k<=j;k++){
                if(p[k]!='*'){
                    return false;
                }
            }
           return true;
           
        }
        if(i>=0 && j<0){
            return false;
            
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }

        if(s[i]==p[j]  || p[j]=='?'){
            return dp[i][j]= f(i-1,j-1,s,p,dp);
        }
        if(p[j]=='*'){
            return dp[i][j]= f(i-1,j,s,p,dp) || f(i,j-1,s,p,dp);
        }

        return false;
    }
    bool isMatch(string s, string p) {
        int i=s.size();
        int j=p.size();
        vector<vector<int>>dp(i+1,vector<int>(j+1,-1));
        return f(i-1,j-1,s,p,dp);
        
    }
};