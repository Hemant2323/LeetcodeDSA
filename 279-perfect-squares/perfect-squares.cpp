class Solution {
public:
    int numSquares(int n) {
        vector<int> coins;
        for(int i=1;i<=n;i++){
            int root=sqrt(i);
            if(root*root==i){
                coins.push_back(i);
            }
        }

        int x=coins.size();
        vector<vector<int>> dp(x,vector<int>(n +1,0));

        

        for(int i=0;i<=n;i++){
            if(i%coins[0]==0){
                dp[0][i]=i/coins[0];
            }
            else{
                dp[0][i]=1e9;
            }
        }

        for(int i=1;i<x;i++){
            for(int j=0 ;j<=n;j++){
                int no=dp[i-1][j];
                int take=INT_MAX;

                if(coins[i]<=j){
                    take=1+dp[i][j-coins[i]];
                }
                dp[i][j]=min(no,take);
            }
        }
        int ans=dp[x-1][n];
        if(ans>=1e9){
            return -1;
        }
        return ans;
    }
};