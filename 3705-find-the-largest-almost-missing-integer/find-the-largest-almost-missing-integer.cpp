class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int xx = *max_element(nums.begin(), nums.end());

        vector<int> hash(xx + 1, 0);
        for (int i = 0; i < nums.size(); i++) {
            hash[nums[i]]++;
        }
        int res = -1;
        int maxxx = -1;
        int count = 0;
        for (int i = 0; i < hash.size(); i++) {
            if (hash[i] == 1) {
                count++;
                if (i == nums[0] || i == nums[nums.size() - 1]) {
                    res = i;
                    maxxx = max(maxxx, res);
                }
            }
        }
        int a=-1;
        int b=-1;
        for(int i=0;i<hash.size();i++){
            if(hash[i]==1){
                a=i;
                b=max(a,b);
            }
        }
        if (k == nums.size()) {
            return xx;
        }

        if(k==1){
            if(count==0){
                return -1;

            }
            else{
                return b;
            }
        }

        return maxxx;
    }
};