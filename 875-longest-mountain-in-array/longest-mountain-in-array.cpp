class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int n = arr.size();

        vector<int> up(n, 0);

        for (int i = 1; i < n; i++) {
            if(arr[i]>arr[i-1]){
                up[i]=up[i-1]+1;
            }
        }
        reverse(arr.begin(),arr.end());
        vector<int> down(n, 0);

        for (int i = 1; i < n; i++) {
            if(arr[i]>arr[i-1]){
                down[i]=down[i-1]+1;
            }
        }
         reverse(down.begin(),down.end());

        int ans=0;
        for(int i=0;i<n;i++){
            if(up[i]>0 && down[i]>0){
                ans=max(ans,up[i]+down[i]+1);
            }
        }
        return  ans;
    }
};