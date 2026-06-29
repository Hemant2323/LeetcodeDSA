class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
       int i=0;
       int j=0;
       int x=nums1.size();
       int y=nums2.size();
        vector<int>arr;
       while(i<x && j<y){
            if(nums1[i]<nums2[j]){
                arr.push_back(nums1[i]);
                i++;
            }
            else if(nums1[i]>nums2[j]){
                 arr.push_back(nums2[j]);
                j++;
            }
            else{
                arr.push_back(nums1[i]);
                arr.push_back(nums2[j]);
                i++;
                j++;
            }
       }
       while(i<x){
         arr.push_back(nums1[i]);
                i++;
       }
       while(j<y){
             arr.push_back(nums2[j]);
                j++;
       }

       float ans;
       int n=arr.size();
       if(n%2!=0){
        ans=arr[n/2];
       }
       else{
        ans=(arr[n/2-1] + arr[n/2])/2.0;
       }

       return ans;
    }
};