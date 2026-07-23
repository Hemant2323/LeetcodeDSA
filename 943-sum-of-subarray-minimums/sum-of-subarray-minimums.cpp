class Solution {
public:
    
    int sumSubarrayMins(vector<int>& arr) {
        int n=arr.size();
        const long long mod=1e9 +7;
        vector<int> left(n);
        vector<int> right(n);

        stack<int> st;
        for(int i=0;i<n;i++){
            while(!st.empty() && arr[st.top()]>arr[i]){
                st.pop();
            }

            if(st.empty()){
                left[i]=-1;
            }
            else{
                left[i]=st.top();
            }
            st.push(i);
        }
        while(!st.empty()){
            st.pop();
        }
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && arr[st.top()]>=arr[i]){
                st.pop();
            }

            if(st.empty()){
                right[i]=n;
            }
            else{
                right[i]=st.top();
            }
            st.push(i);
        }
        long long ans=0;

        for(int i=0;i<n;i++){
            long long lefft=i-left[i];
            long long rigght=right[i]-i;

            ans=(ans+arr[i]*lefft*rigght)%mod;
        }
        return ans;
    }
};