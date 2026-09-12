class Solution {
public:
         int f(int i,int j,vector<vector<int>>& dp,vector<vector<int>>& grid){
        // base case
       
        if(i==0 && j==0 ){
            return grid[0][0];
        }
        if(i<0 || j<0){
            return INT_MAX;
        }

        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        //up
        int up=f(i-1,j,dp,grid);
        if(up!=INT_MAX){
            up+=grid[i][j];
        }
        // left
        int left=f(i,j-1,dp,grid);
        if(left!=INT_MAX){
            left+=grid[i][j];
        }

        return  dp[i][j]= min(up,left);


        
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return f(m-1,n-1,dp,grid);
    }
};