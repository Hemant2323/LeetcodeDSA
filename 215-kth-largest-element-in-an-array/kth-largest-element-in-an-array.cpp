class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        //  nth_element(nums.begin(), nums.end() - k, nums.end());

        // return nums[nums.size()-k];
        int maxx = *max_element(nums.begin(), nums.end());
        int minn = *min_element(nums.begin(), nums.end());


        vector<int> hash(maxx-minn + 1, 0);
        for (int i = 0; i < nums.size(); i++) {
            hash[nums[i]-minn]++;
        }
        int res;
        for (int i = hash.size() - 1; i >= 0; i--) {
            if (hash[i] > 0) {
                while (hash[i] != 0) {
                    hash[i]--;
                    k--;
                    if (k == 0) {
                        return i+minn;
                    }
                }
            }
        }
        return -1;
    }
};