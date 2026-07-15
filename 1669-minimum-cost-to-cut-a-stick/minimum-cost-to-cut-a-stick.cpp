class Solution {
public:
    int f(int i,int j,vector<int> &cuts,vector<vector<int>>&dp){
        if(i>j){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int mini=1e9;
        int cost=0;
        for(int ind=i;ind<=j;ind++){
            cost=cuts[j+1]-cuts[i-1]  + f(i,ind-1,cuts,dp)+f(ind+1,j,cuts,dp);
            mini=min(mini,cost);
        }
        return dp[i][j]= mini;
    }
    int minCost(int n, vector<int>& cuts) {
        sort(cuts.begin(),cuts.end());
        cuts.push_back(n);
        reverse(cuts.begin(),cuts.end());
        cuts.push_back(0);
        reverse(cuts.begin(),cuts.end());
        int nn=cuts.size()-1;

        vector<vector<int>>dp(nn+1,vector<int>(n+1,-1));

        return f(1,nn-1,cuts,dp);

    }
};