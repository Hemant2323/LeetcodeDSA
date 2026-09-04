class Solution {
public:
    string sortVowels(string s) {
    

        int x = s.size();

        string vowel ="";
        for (int i = 0; i < x; i++) {

            if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' ||
                s[i] == 'u' || s[i] == 'A' || s[i] == 'E' || s[i] == 'I' ||
                s[i] == 'O' || s[i] == 'U') {
                vowel += s[i];
            }
        }

      //  sort(vowel.begin(), vowel.end());
      vector<int> v(123,0);
      for(int i=0;i<vowel.size();i++){
        int x=(int)vowel[i];
        v[x]++;
      }
      string sortedvowel="";
      for(int i=0;i<123;i++){
        if(v[i]>0){
            while(v[i]>0){
                sortedvowel+=(char)i;
                v[i]--;
            }
        }
      }
        int index = 0;
        for (int i = 0; i < x; i++) {
            if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' ||
                s[i] == 'u' || s[i] == 'A' || s[i] == 'E' || s[i] == 'I' ||
                s[i] == 'O' || s[i] == 'U'){
                    s[i]=sortedvowel[index];
                    index++;
                }
        }

        return s;
    }
};