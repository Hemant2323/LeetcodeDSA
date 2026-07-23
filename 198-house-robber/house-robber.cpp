class Solution {
public:
// MLE
    int f(vector<int> arr,int ind,vector<int>&dp){
        if(ind==0){
            return arr[ind];
        }
        if(ind<0){
            return 0;
        }
        if(dp[ind]!=-1){
            return dp[ind];
        }
        int pick=arr[ind]+f(arr,ind-2,dp);
        int not_pick= f(arr,ind-1,dp);

        return dp[ind]= max(pick,not_pick);
    }

   
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size()+1,-1);
         return f(nums,nums.size()-1,dp);  
    //    int n=nums.size();
    //    int prev=nums[0];

    //    int prev2=0;
    //    for(int i=1;i<n;i++){
    //     int take=nums[i];
    //     if(i>1){
    //         take+=prev2;
    //     }
    //     int not_take=prev;

    //     int curr=max(take,not_take);
    //     prev2=prev;
    //     prev=curr;
    //    }

    //    return prev;

    }
};