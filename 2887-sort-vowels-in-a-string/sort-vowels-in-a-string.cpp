class Solution {
public:
    string sortVowels(string s) {
        // int x=s.size();
        // vector<char> v;
        // vector<char> c(x,' ');
        // for(int i=0;i<x;i++){
        //     if(s[i]=='a'|| s[i]=='e'|| s[i]=='i'|| s[i]=='o'|| s[i]=='u'||
        //     s[i]=='A'|| s[i]=='E'|| s[i]=='I'|| s[i]=='O'|| s[i]=='U'){
        //         v.push_back(s[i]);
        //     }
        //     else{
        //         c[i]=s[i];
        //     }
        // }
        // sort(v.begin(),v.end());
        // int index=0;
        // for(int i=0;i<x;i++){
        //     if(c[i]==' '){
        //         c[i]=v[index];
        //         index++;
        //     }
        // }
        // string res="";
        // for(int i=0;i<x;i++){
        //     char ch=c[i];
        //     res+=ch;
        // }
        // return res;

        int x = s.size();

        string vowel ="";
        for (int i = 0; i < x; i++) {

            if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' ||
                s[i] == 'u' || s[i] == 'A' || s[i] == 'E' || s[i] == 'I' ||
                s[i] == 'O' || s[i] == 'U') {
                vowel += s[i];
            }
        }

        sort(vowel.begin(), vowel.end());
        int index = 0;
        for (int i = 0; i < x; i++) {
            if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' ||
                s[i] == 'u' || s[i] == 'A' || s[i] == 'E' || s[i] == 'I' ||
                s[i] == 'O' || s[i] == 'U'){
                    s[i]=vowel[index];
                    index++;
                }
        }

        return s;
    }
};