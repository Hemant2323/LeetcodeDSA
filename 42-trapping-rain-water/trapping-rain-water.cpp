class Solution {
public:
    int trap(vector<int>& arr) {
        int x=arr.size();
        int leftmax[x];
        int rightmax[x];
        leftmax[0]=arr[0];
        rightmax[x-1]=arr[x-1];
        for(int i=1;i<x;i++){
            leftmax[i]=max(arr[i],leftmax[i-1]);
        }
        for(int i=x-2;i>=0;i--){
            rightmax[i]=max(arr[i],rightmax[i+1]);
        }
        int sum=0;
        for(int i=0;i<x;i++){
            int space=min(leftmax[i],rightmax[i]);
            int y;
            // if(space>arr[i]){
            //     y=space-arr[i];
            // }
            // else{
            //     y=arr[i]-space;
            // }
            y=abs(space-arr[i]);
            sum+=y;
        }

        return sum;
    }
};