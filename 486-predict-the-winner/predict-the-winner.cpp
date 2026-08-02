class Solution {
public:
    int f(int i,int j,vector<int> & nums,vector<vector<int>>& dp){
        
            if(i==j){
                return nums[i];
            }
            if(dp[i][j]!=-1){
                return dp[i][j];
            }
            int pick=0,not_pick=0;
             pick=nums[i]-f(i+1,j,nums,dp);
             not_pick=nums[j]-f(i,j-1,nums,dp);

            
        
        return dp[i][j]= max(pick,not_pick);
    }
    bool predictTheWinner(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> dp (n,vector<int>(n,-1));
        int dif=f(0,n-1,nums,dp);
        if(dif>=0){
            return true;
        }
        return false;
    }
};