class Solution {
public:
    int solve(vector<int>& nums,int index,int sum,int n,int target,vector<vector<int>>&dp,int x){
        if(index==n){
            return sum==target;
        }
        if(dp[index][sum+x]!=-1){
            return dp[index][sum+x];
        }
        int add=solve(nums, index + 1, sum + nums[index], n, target,dp,x);
        int sub= solve(nums, index + 1, sum - nums[index], n, target,dp,x);

        return dp[index][sum+x]=add+sub;
        
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        int total=accumulate(nums.begin(),nums.end(),0);
        int x=total;
        vector<vector<int>>dp(n,vector<int>(2*total+1,-1));
        return solve(nums,0,0,n,target,dp,x);
    }
};