class Solution {
public:
    int smallestNumber(int n, int t) {
       
        int res=n;
        for(int i=n;i<=n*t;i++){
            int ans=i;
            int mul=1;
            while(ans>0){
                int digit=ans%10;
                mul*=digit;
                ans/=10;
            }

            if(mul%t==0){
                res=i;
                break;
            }
        }
        return res;
    }
};