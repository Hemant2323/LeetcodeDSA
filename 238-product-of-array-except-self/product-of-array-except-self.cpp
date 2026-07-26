class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int prod = 1;
        int n = nums.size();
      
        int zero = 0;

        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                zero++;
            }
        }

       
        if (zero > 1) {
            return vector<int>(n, 0);
        }
       else if (zero == 0) {
            for (int i = 0; i < n; i++) {
                prod *= nums[i];
            }

            for(int i=0;i<n;i++){
                nums[i]=prod/nums[i];
            }
        }
        else{
            for(int i=0;i<n;i++){
                if(nums[i]==0){
                    continue;
                }
                else{
                    prod*=nums[i];
                }
            }
            for(int i=0;i<n;i++){
                if(nums[i]!=0){
                    nums[i]=0;
                }
                else{
                    nums[i]=prod;
                }
            }
        }
        return nums;
    }
};