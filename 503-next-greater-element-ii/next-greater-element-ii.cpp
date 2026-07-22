class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> res(nums.size(),-1);
        stack<int> st;
        int n=nums.size()-1;
         for(int i=n;i>=0;i--){
            while(!st.empty() && st.top()<=nums[i]){
                st.pop();
            }
            st.push(nums[i]);
         }
        for(int i=n;i>=0;i--){
            while(!st.empty() && st.top()<=nums[i]){
                st.pop();
            }
            if(st.empty()){
                res[i]=-1;
            }
            else{
                res[i]=st.top();
            }

            st.push(nums[i]);
        }
       
        return res;
    }
};