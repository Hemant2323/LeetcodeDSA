class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        int even=0,odd=0;
        for(int i=1;i<=2*n;i++){
            if(i%2==0){
                even+=i;
            }
            else{
                odd+=i;
            }
        }

        int minn=min(even,odd);
        int maxx=1;

        for(int i=1;i<=minn;i++){
            if(even%i==0 && odd%i==0){
                maxx=max(maxx,i);
            }
        }

        return maxx;
    }
};