class Solution {
public:
 int f(vector<int> arr,int ind,int start,vector<int>&dp){
        if(ind==start){
            return arr[ind];
        }
        if(ind<start){
            return 0;
        }
        if(dp[ind]!=-1){
            return dp[ind];
        }
        int pick=arr[ind]+f(arr,ind-2,start,dp);
        int not_pick= f(arr,ind-1,start,dp);

        return dp[ind]= max(pick,not_pick);
    }
    int rob(vector<int>& nums) {
        
            
       int n=nums.size();
        if (n == 1) {
            return nums[0];
        }
       vector<int> dp1(nums.size(),-1);

       int ans1=f(nums,n-2,0,dp1);

       vector<int> dp2(nums.size(),-1);
       int ans2=f(nums,n-1,1,dp2);

        return max(ans1,ans2);
       
    //     int ans1=nums[0],ans2=0;
    //    int n=nums.size();
    //    if(n>1){
    //         int prev=nums[1];

    //     int prev2=0;
    //     for(int i=2;i<n;i++){
    //         int take=nums[i];
    //         if(i>1){
    //             take+=prev2;
    //         }
    //         int not_take=prev;

    //         int curr=max(take,not_take);
    //         prev2=prev;
    //         prev=curr;
    //     }

    //      ans1= prev;


        
    //     int prevv=nums[0];

    //     int prevv2=0;
    //     for(int i=1;i<n-1;i++){
    //         int take=nums[i];
    //         if(i>1){
    //             take+=prevv2;
    //         }
    //         int not_take=prevv;

    //         int curr=max(take,not_take);
    //         prevv2=prevv;
    //         prevv=curr;
    //     }

    //      ans2= prevv;
    //    }
       

    //    return max(ans1,ans2);

    }
};