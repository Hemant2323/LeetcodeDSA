class Solution {
public:
    //brute{
        
        // int x = s.size();

        // int i = 0;
        // int j = s.size() - 1;

        // while (i < j) {

        //     if (s[i] == s[j]) {
        //         i++;
        //         j--;
        //     } else {
        //         s.insert(s.begin() + j + 1, s[i]);
        //         i++;
        //         // j stays at the same index
        //     }
        // }

        // int count = s.size() - x;

        // if (i == j) {
        //     return count;
        // }

        // if (s[i] != s[j]) {
        //     count++;
        // }

        // return count;
    //}
    int f(int i,int j,string &s,vector<vector<int>> &dp){
        if(i>=j){
            return 0;
        }
        if(s[i]==s[j]){
            return f(i+1,j-1,s,dp);
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        
            return dp[i][j]= 1+min(f(i+1,j,s,dp),f(i,j-1,s,dp));
        
    }
    int minInsertions(string s) {
        // int x=s.size();
        // vector<vector<int>>dp(x+1,vector<int>(x+1,-1));
       
        // return f(0,s.size()-1,s,dp);

        string s1=s;
        reverse(s.begin(),s.end());
        int n = s.size();
        int m = s1.size();
       // vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        

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
        return n- ahead[0];

    }
};