class Solution {
public:
    void sortColors(vector<int>& nums) {
        // int mx=*max_element(nums.begin(),nums.end());
        // vector<int> freq(mx+1, 0);
        // for (int x : nums) {
        //         freq[x]++;
        // }

        // int idx = 0;
        // for (int i = 0; i <= mx; i++) {
        //     while (freq[i] > 0) {
        //         nums[idx++] = i;
        //         freq[i]--;
        //     }
        // }

        int n=nums.size()-1;
        int i=0,j=0,k=n;
        while(j<=k){
            if(nums[j]==2){
                swap(nums[j],nums[k]);
                k--;
            }
            else if(nums[j]==1){
                j++;
            }
            else{
                swap(nums[i],nums[j]);
                i++;
                j++;
            }
        }


    }
};