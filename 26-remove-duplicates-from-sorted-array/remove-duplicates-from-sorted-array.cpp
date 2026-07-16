class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
         int x=nums.size();
        // vector<int>arr(201,0);
        // for(int i=0;i<x;i++){
        //     if(nums[i]>=0){
        //         arr[nums[i]]++;
        //     }
        //     else{
        //         arr[100-nums[i]]++;
        //     }
        // }
        //  int count=0;
        // vector<int>y;
        // for(int i=arr.size()-1;i>=101;i--){
        //     if(arr[i]>0){
        //         count++;
        //         y.push_back(100-i);
        //     }
        // }
        // for(int i=0;i<101;i++){
        //     if(arr[i]>0){
        //         count++;
        //         y.push_back(i);
        //     }
        // }
        // nums=y;
        // return count;
        int count=0;
        int i=0,j;
       for(j=1;j<x;j++){
            if(nums[j]==nums[i]){
                continue;
            }

            else{
                i++;
                nums[i]=nums[j];
                count++;
            }
        }
        return i+1;
        

      


       
    }
};