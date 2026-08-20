class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int>s;
        int minn = *min_element(nums.begin(), nums.end());
        int maxx = *max_element(nums.begin(), nums.end());

        vector<int> hash(maxx - minn + 1, 0);

        for (int i = 0; i < nums.size(); i++) {
            hash[nums[i] - minn]++;
        }
        for (int i = 0; i < hash.size(); i++) {
            while (hash[i] > 0) {
                s.push_back(i + minn);
                hash[i]--;
            }
        }

        int i = 0, j = nums.size() - 1;
        while (i <= j && nums[i] == s[i]) {
            i++;
        }
        while (j >= i && nums[j] == s[j]) {
            j--;
        }
        if (i > j) {
            return 0;
        }
        return j - i + 1;
    }
};