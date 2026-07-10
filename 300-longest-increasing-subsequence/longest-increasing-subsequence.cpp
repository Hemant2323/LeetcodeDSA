class Solution {
public:
    int f(int ind, int prev_ind, vector<int>& nums, vector<vector<int>>& dp) {
        if (ind == nums.size()) {
            return 0;
        }
        if (dp[ind][prev_ind + 1] != -1) {
            return dp[ind][prev_ind + 1];
        }

        int len = f(ind + 1, prev_ind, nums, dp);
        int len1 = 0;
        if (prev_ind == -1 || nums[ind] > nums[prev_ind]) {
            len1 = 1 + f(ind + 1, ind, nums, dp);
        }

        return dp[ind][prev_ind + 1] = max(len, len1);
    }
    int lengthOfLIS(vector<int>& arr) {
        //int n = nums.size();
       // vector<vector<int>> dp(n+1, vector<int>(n + 1, 0));
        // return f(0,-1,nums,dp);
        // vector<int> curr(n+1,0),next(n+1,0);

        // for (int ind = n - 1; ind >= 0; ind--) {
        //     for (int prev_ind = ind - 1; prev_ind >= -1; prev_ind--) {
        //         int len = 0;

        //         if (ind <n) {
        //             len = next[prev_ind+1];
        //             int len1 = 0;
        //             if (prev_ind == -1 || nums[ind] > nums[prev_ind]) {
        //                 len1 = 1 + next[ind+1];
        //             }

        //             curr[prev_ind + 1] = max(len, len1);
        //         }
        //     }
        //     next=curr;
        // }

        // return next[0];


        int n = arr.size();
      
        vector<int> dp(n,1);
        int maxi=1;
        for(int i=0;i<n;i++){
            for(int prev=0;prev<i;prev++){
                if(arr[prev]<arr[i] ){
                    dp[i]=max(dp[i],1+dp[prev]);
                }
            }
            maxi=max(maxi,dp[i]);
        }

        return maxi;
    }
};