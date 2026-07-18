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
    int findGCD(vector<int>& nums) {
        int x=*min_element(nums.begin(),nums.end());
        int y=*max_element(nums.begin(),nums.end());
        return gcd(x,y);
    }
};