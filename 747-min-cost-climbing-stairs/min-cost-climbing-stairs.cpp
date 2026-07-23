class Solution {
public:
    int f(int ind,vector<int> & cost,vector<int> &dp){
        if(ind==0){
            return cost[ind];
        }
        if(ind<0){
            return 0;
        }
        if(dp[ind]!=-1){
            return dp[ind];
        }

        int x=cost[ind]+min(f(ind-1,cost,dp) , f(ind-2,cost,dp));
        
        return dp[ind]=x;
    }
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp(cost.size()+1,-1);
        return min(f(cost.size()-1,cost,dp),f(cost.size()-2,cost,dp));
    }
};