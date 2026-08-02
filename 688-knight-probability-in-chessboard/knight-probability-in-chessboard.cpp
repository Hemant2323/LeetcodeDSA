class Solution {
public:
    double f(int n, int k, int row, int column,vector<vector<vector<double>>> &dp){
        if(k==0){
            return 1.0;

        }
        if(dp[row][column][k]!=-1.0){
            return dp[row][column][k];
        }


        int roww[8]={2,1,-1,-2,-2,-1,1,2};
        int coll[8]={1,2,2,1,-1,-2,-2,-1};


        double prob=0.0;

        for(int i=0;i<8;i++){
            int newrow=row+roww[i];
            int newcol=column+coll[i];

            if(newrow>=0 && newcol>=0 && newrow<n && newcol<n){
                prob+=f(n,k-1,newrow,newcol,dp);
            }
        }
        return dp[row][column][k]= prob/8.0;
    }
    double knightProbability(int n, int k, int row, int column) {
        vector<vector<vector<double>>> dp(n,vector<vector<double>>(n,vector<double>(k+1,-1.0)));
        return f(n,k,row,column,dp);
    }
};