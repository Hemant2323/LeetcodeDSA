class Solution {
public:
    int solve(vector<int>& nums,int index,int sum,int n,int target){
        if(index==n){
            return sum==target;
        }
        return solve(nums, index + 1, sum + nums[index], n, target)
             + solve(nums, index + 1, sum - nums[index], n, target);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        
        return solve(nums,0,0,nums.size(),target);
    }
};