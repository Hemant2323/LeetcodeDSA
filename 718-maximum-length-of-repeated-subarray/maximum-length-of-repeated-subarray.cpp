class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        vector<int> curr(m+1,0),ahead(m+1,0);
        int mx=INT_MIN;
        for (int i = n-1; i >=0; i--) {
            for (int j = m-1; j >=0; j--) {
                if (nums1[i] == nums2[j]) {
                    curr[j]= 1 + ahead[j+1];
                    
                }
                else{
                    curr[j] = 0;
                }
                mx=max(mx,curr[j]);
                 
            }
            ahead=curr;
        }
        return mx;

    }
};