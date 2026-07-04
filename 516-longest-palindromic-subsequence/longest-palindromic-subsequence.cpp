class Solution {
public:
    
    int longestPalindromeSubseq(string s) {
        string s1=s;
        reverse(s.begin(),s.end());
        int n = s.size();
        int m = s1.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        

         vector<int> curr(m+1,0),ahead(m+1,0);

        for (int i = n-1; i >=0; i--) {
            for (int j = m-1; j >=0; j--) {
                if (s[i] == s1[j]) {
                    curr[j]= 1 + ahead[j+1];
                }
                else{
                    curr[j] = max(curr[j+1], ahead[j]);
                }
                 
            }
            ahead=curr;
        }
        return ahead[0];
    }
};