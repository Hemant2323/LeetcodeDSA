class Solution {
public:
    bool uniformArray(vector<int>& nums1) {

        vector<int> even;
        vector<int> odd;

        bool hasOdd = false, hasEven = false;

        for (int x : nums1) {
            if (x % 2 == 0)
                hasEven = true;
            else
                hasOdd = true;
        }

        if (!hasOdd || !hasEven  )
            return true;

        else {
            int mn=*min_element(nums1.begin(),nums1.end());
            int oddcount = 0, evencount = 0;
            for (int i = 0; i < nums1.size(); i++) {
                if (nums1[i] % 2 == 0) {
                    evencount++;
                } else {
                    oddcount++;
                }
            }

            if (evencount == oddcount && (mn%2==0)) {
                return false;
            }

            if(mn%2==0){
                return false;
            }
        }

        return true;
    }
};