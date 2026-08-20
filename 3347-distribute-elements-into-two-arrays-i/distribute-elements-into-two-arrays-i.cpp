class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        vector<int> arr1;
        vector<int> arr2;

        arr1.push_back(nums[0]);
        arr2.push_back(nums[1]);
        int ind1=1;
        int ind2=1;
        for(int i=2;i<nums.size();i++){
            if(arr1[ind1-1]>arr2[ind2-1]){
                arr1.push_back(nums[i]);
                ind1++;
            }
            else{
                arr2.push_back(nums[i]);
                ind2++;
            }
        }

        arr1.insert(arr1.end(),arr2.begin(),arr2.end());
        return arr1;
    }
};