class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
        reverse(shifts.begin(),shifts.end());
        for(int i=1;i<shifts.size();i++){
            shifts[i] = (shifts[i] + shifts[i - 1]) % 26;
        }
        reverse(shifts.begin(),shifts.end());
        
        int n=s.size();
        for(int i=0;i<n;i++){
            s[i]='a' + (s[i] - 'a' + shifts[i]) % 26;
        }
        return s;
    }
};