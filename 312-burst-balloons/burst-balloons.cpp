class Solution {
public:
    int f(int i,int j,vector<int>& nums,vector<vector<int>>&dp){
        if(i>j){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int maxx=-1e9;
        for(int ind=i;ind<=j;ind++){
            int cost=nums[i-1]*nums[ind]*nums[j+1]+f(i,ind-1,nums,dp)+f(ind+1,j,nums,dp);
            maxx=max(maxx,cost);

        }
        return dp[i][j]=maxx;
    }
    int maxCoins(vector<int>& nums) {
        nums.push_back(1);
        nums.insert(nums.begin(),1);
        int i=1,j=nums.size()-2;
        vector<vector<int>>dp(j+1,vector<int>(j+1,-1));
        return f(i,j,nums,dp);

    }
};