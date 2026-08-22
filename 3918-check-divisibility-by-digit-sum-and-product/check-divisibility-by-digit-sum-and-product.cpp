class Solution {
public:
    bool checkDivisibility(int n) {
        int y=n;
        int sum=0,mul=1;
        while(n>0){
          int  x= n%10;
          sum+=x;
          mul*=x;
          n/=10;
        }
        return y%(mul+sum)==0;
    }
};