class Solution {
public:
    string smallestPalindrome(string s) {
        // string x = sort(s.begin(), s.end());
        vector<int> freq(26, 0);
        for (int i = 0; i < s.size(); i++) {
            freq[s[i] - 'a']++;
        }
        string res;
        for (int i = 0; i < freq.size(); i++) {
            if (freq[i] > 0) {
                int half = freq[i] / 2;

                while (half > 0) {
                    res.push_back(i + 'a');
                    half--;
                }
            }
        }
        string temp=res;
        for (int i = 0; i < freq.size(); i++) {
            if (freq[i] % 2 != 0) {
                
                    temp.push_back(i + 'a');
                   break;
                
            }
        }
        reverse(res.begin(),res.end());
        temp+=res;

        return temp;
    }
};