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

        vector<int> mx;
        int n = nums.size();
        int maxx = nums[0];
        for (int i = 0; i < n; i++) {
             maxx = max(nums[i], maxx);
            mx.push_back(maxx);
        }

        vector<int> prefixgcd;
        for(int i=0;i<mx.size();i++){
            int x=gcd(nums[i],mx[i]);
            prefixgcd.push_back(x);
        }


        sort(prefixgcd.begin(),prefixgcd.end());
        int i=0,j=n-1;
        long long sum=0;
        while(i<j){
            int x=gcd(prefixgcd[i],prefixgcd[j]);
            sum+=x;
            i++;
            j--;
        }

        return sum;
        

    }
};