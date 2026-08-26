class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
    
        int count1 = 0;
        int len = 0;
        int j;
        for (int i = 0; i < s.length(); i++) {
         
            if (s[i] == '1') {
                count1++;
            }
            if (count1 == k) {
                j = i;
               
                break;
            }
        }
         if (count1!=k) {
            return "";
        }
        int i = 0;
        int minLen=1e9;
        int ansStart,ansEnd;
        while (j < s.length() && i <= j) {

            int freq = count(s.begin() + i, s.begin() + j + 1, '1');

            if (freq == k) {

                int currLen = j - i + 1;

                if (currLen < minLen) {
                    minLen = currLen;
                    ansStart = i;
                    ansEnd = j;
                }
                else if(currLen==minLen){
                    string curr=s.substr(i,currLen);
                    string prev=s.substr(ansStart,ansEnd-ansStart+1);

                    if(curr<prev){
                        ansStart=i;
                        ansEnd=j;

                    }
                }

                i++;
            } else {
                j++;
            }
        }

       

       
        return s.substr(ansStart,ansEnd-ansStart+1);
    }
};