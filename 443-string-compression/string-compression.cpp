class Solution {
public:
    int compress(vector<char>& chars) {
        int n=chars.size();
        string res="";
        int i=0,j=1;
        int count=1;

        while(j<=n){
            
            char x=chars[i];
            if(j<n && chars[j]==x){
                count++;
                j++;

            }
            else{
                res+=x;
                if(count>1){
                    res+=to_string(count);
                }
                i=j;
                j++;

                
                

                count=1;
            }
        }

        for(int i=0;i<res.size();i++){
            chars[i]=res[i];
        }
        return res.size();
    }
};