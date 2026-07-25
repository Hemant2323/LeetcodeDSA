class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> st;
        for(int i=0;i<num.size();i++){
            while(!st.empty() && k>0 && (st.top()-'0')>(num[i]-'0')){
                st.pop();
                k--;
            }

            st.push(num[i]);
        }
        while(k>0){
            st.pop();
            k--;
        }
        string res="";
        while(!st.empty()){
            res+=st.top();
            st.pop();
        }
        reverse(res.begin(),res.end());
        string ans="";
        int x;
        for(int i=0;i<res.size();i++){
            if(res[i]-'0' >0){
                x=i;
                break;
            }
        }
        for(int i=x;i<res.size();i++){
            ans+=res[i];
        }
        if(ans==""){
            return "0";
        }
        return ans;
    }
};