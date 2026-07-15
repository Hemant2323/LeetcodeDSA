class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        int even=n*(n+1),odd=n*n;
        

        int minn=min(even,odd);
        int maxx=1;

        for(int i=1;i<=minn/2;i++){
            if(even%i==0 && odd%i==0){
                maxx=max(maxx,i);
            }
        }

        return maxx;
    }
};