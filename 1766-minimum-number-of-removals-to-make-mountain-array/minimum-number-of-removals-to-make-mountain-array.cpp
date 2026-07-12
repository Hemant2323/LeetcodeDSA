class Solution {
public:
    int minimumMountainRemovals(vector<int>& arr) {
        int n = arr.size();

        vector<int> dp(n, 1);

        for (int i = 0; i < n; i++) {
            for (int prev = 0; prev < i; prev++) {
                if (arr[prev] < arr[i]) {
                    dp[i] = max(dp[i], 1 + dp[prev]);
                }
            }
        }
        reverse(arr.begin(),arr.end());
        vector<int> dp1(n, 1);

        for (int i = 0; i < n; i++) {
            for (int prev = 0; prev < i; prev++) {
                if (arr[prev] < arr[i]) {
                    dp1[i] = max(dp1[i], 1 + dp1[prev]);
                }
            }
        }
         reverse(dp1.begin(),dp1.end());

        int ans=1;
        for(int i=0;i<n;i++){
            if(dp[i]>1 && dp1[i]>1){
                ans=max(ans,dp[i]+dp1[i]-1);
            }
        }
        return n- ans;
        
    }
};