class Solution {
public:
    int arrangeCoins(int n) {
        int res;
        
        for(int i=1;i<n;i++){
            n=n-i;
            
            if(n<0){
                res=i-1;
                break;
            }
        }
        return res;
    }
};