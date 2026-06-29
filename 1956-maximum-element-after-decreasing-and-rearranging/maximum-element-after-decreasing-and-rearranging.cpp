class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        if(arr[0]!=1){
            arr[0]=1;
        }
        int x=arr.size();
        for(int i=1;i<x;i++){
            int n=abs(arr[i]-arr[i-1]);
            if(n>1){
                arr[i]=arr[i-1]+1;
            }
        }


        return *max_element(arr.begin(),arr.end());
    }
};