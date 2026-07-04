class Solution {
public:
    int minDistance(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        // return solve(0,0,text1,text2,dp);

         vector<int> curr(m+1,0),ahead(m+1,0);

        for (int i = n-1; i >=0; i--) {
            for (int j = m-1; j >=0; j--) {
                if (text1[i] == text2[j]) {
                    curr[j]= 1 + ahead[j+1];
                }
                else{
                    curr[j] = max(curr[j+1], ahead[j]);
                }
                 
            }
            ahead=curr;
        }
        return n +m- 2*ahead[0];
    }
};