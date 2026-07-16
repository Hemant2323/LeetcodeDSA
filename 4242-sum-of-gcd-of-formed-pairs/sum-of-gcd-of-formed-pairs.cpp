class Solution {
public:
    int gcd(int a, int b) {
        while (b) {
            int rem = a % b;
            a = b;
            b = rem;
        }
        return a;
    }
    long long gcdSum(vector<int>& nums) {

        int n = nums.size();

        vector<int> prefixgcd;
        prefixgcd.reserve(n);

        int maxx = nums[0];

        for (int i = 0; i < n; i++) {
            maxx = max(maxx, nums[i]);
            prefixgcd.push_back(gcd(nums[i], maxx));
        }

        sort(prefixgcd.begin(), prefixgcd.end());

        int i = 0;
        int j = n - 1;
        long long sum = 0;

        while (i < j) {
            sum += gcd(prefixgcd[i], prefixgcd[j]);
            i++;
            j--;
        }

        return sum;
    }
};