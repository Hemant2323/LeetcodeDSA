class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
          int x = nums.size();
        vector<int> max1;
        vector<int> min1;
        int maxx = nums[0], minn = nums[x - 1];
        for (int i = 0; i < x; i++) {
            maxx = max(maxx, nums[i]);
            max1.push_back(maxx);
        }

        for (int i = x - 1; i >= 0; i--) {
            minn = min(minn, nums[i]);
            min1.push_back(minn);
        }

        reverse(min1.begin(), min1.end());

        int ans = -1;
        for (int i = 0; i < x; i++) {
            int y = max1[i] - min1[i];
            if (y <= k) {
                ans = i;
                break;
            }
        }

        return ans;
    }
};