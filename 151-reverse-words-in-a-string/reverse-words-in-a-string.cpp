class Solution {
public:
    string reverseWords(string s) {
        

        int n=s.size();

        int read=0;
        int write=0;
        while(read<n){
            while(read<n && s[read]== ' '){
            read++;
            }
            while(read<n && s[read]!=' '){
                s[write]=s[read];
                write++;
                read++;
            }
            while(read<n && s[read]== ' '){
                read++;
            }
            if(read<n){
                s[write]=' ';
                write++;
            }


        }

        s.resize(write);

        n=s.size();
        
        reverse(s.begin(),s.end());
        int prev=0;
        int curr=0;
        while(curr<n){
            while (curr < n && s[curr] != ' ') {
                curr++;
            }
            reverse(s.begin()+prev,s.begin()+curr);
            prev=curr+1;
            curr++;


        }
       
        return s;
    }
};