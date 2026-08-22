class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int mx=*max_element(nums.begin(),nums.end());
        int mn=*min_element(nums.begin(),nums.end());
        vector<int>freq(mx+1,0);
        vector<int>freq1(((-1)*mn)+1,0);
        for(int i=0;i<nums.size();i++){
            if(nums[i]>=0){
                 freq[nums[i]]++;
            }
            else{
                freq1[(-1)*nums[i]]++;
            }
           
        }
        int x;
        for(int i=0;i<(freq.size());i++){
            if(freq[i]==1){
                x= i;
                break;
            }
        }
         for(int i=0;i<(freq1.size());i++){
            if(freq1[i]==1){
                x= (-1)*i;
                break;
            }
        }
        
        return x;
    }
};