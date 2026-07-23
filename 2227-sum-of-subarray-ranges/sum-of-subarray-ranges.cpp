class Solution {
public:
    long long subArrayRanges(vector<int>& arr) {
               int n=arr.size();
        
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
        long long sum_min=0;

        for(int i=0;i<n;i++){
            long long lefft=i-left[i];
            long long rigght=right[i]-i;

            sum_min=(sum_min+arr[i]*lefft*rigght);
        }

        vector<int> lleft(n);
        vector<int> rright(n);

        stack<int> stt;
        for(int i=0;i<n;i++){
            while(!stt.empty() && arr[stt.top()]<arr[i]){
                stt.pop();
            }

            if(stt.empty()){
                lleft[i]=-1;
            }
            else{
                lleft[i]=stt.top();
            }
            stt.push(i);
        }
        while(!stt.empty()){
            stt.pop();
        }
        for(int i=n-1;i>=0;i--){
            while(!stt.empty() && arr[stt.top()]<=arr[i]){
                stt.pop();
            }

            if(stt.empty()){
                rright[i]=n;
            }
            else{
                rright[i]=stt.top();
            }
            stt.push(i);
        }
        long long sum_max=0;

        for(int i=0;i<n;i++){
            long long lefft=i-lleft[i];
            long long rigght=rright[i]-i;

            sum_max=(sum_max+arr[i]*lefft*rigght);
        }
        return sum_max-sum_min;
       
    }
};