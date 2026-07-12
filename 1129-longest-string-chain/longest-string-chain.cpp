class Solution {
public:
    bool compare(string s, string t) {
        // if (t.size() != s.size() + 1) {
        //     return false;
        // }

        int i = 0, j = 0;

        int count = 0;
        while (i < s.size() && j < t.size()) {
            if (s[i] == t[j]) {
                i++;
                j++;
            } else {
                j++;
            }
        }
        if (i != s.size()) {
            return false;
        }

        return true;
    }
    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(),
             [](string& a, string& b) { return a.size() < b.size(); });
        int n = words.size();

        vector<int> dp(n, 1);
        int maxi = 1;
        for (int i = 0; i < n; i++) {
            for (int prev = 0; prev < i; prev++) {
                if (words[i].size() != words[prev].size() + 1) {
                    continue;
                }

                if (compare(words[prev], words[i])) {
                    dp[i] = max(dp[i], 1 + dp[prev]);
                }
            }
            maxi = max(maxi, dp[i]);
        }

        return maxi;
    }
};