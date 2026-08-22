class Solution {
public:
    int f(int i,int j,vector<int> & nums,vector<vector<int>>& dp){
       if(i==j){
        return nums[i];
       }
       if(dp[i][j]!=-1){
        return dp[i][j];
       }

       int leftpick=0,rightpick=0;
       leftpick=nums[i]-f(i+1,j,nums,dp);
       rightpick=nums[j]-f(i,j-1,nums,dp);

       return dp[i][j]=max(leftpick,rightpick);
    }
    bool predictTheWinner(vector<int>& nums) {

       


        int n=nums.size();
        vector<vector<int>> dp (n,vector<int>(n,-1));
        int diff=f(0,n-1,nums,dp);
        if(diff>=0){
            return true;
        }
        return false;






    }
};