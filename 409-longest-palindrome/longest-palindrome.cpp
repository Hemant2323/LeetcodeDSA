class Solution {
public:
    int longestPalindrome(string s) {
        vector<int> hash(52, 0);

        for (char ch : s) {
            if (ch >= 'A' && ch <= 'Z') {
                hash[ch - 'A']++;
            }
            else {
                hash[ch - 'a' + 26]++;
            }
        }

        int count = 0;
        int maxx2 = 0;
        int count1 = 0;

        vector<int> odd;

        for (int i = 0; i < hash.size(); i++) {
            if (hash[i] % 2 == 0) {
                count += hash[i];
            }
            else {
                odd.push_back(hash[i]);
            }
        }

        if (odd.size() > 0) {
            for (int i = 0; i < odd.size(); i++) {
                maxx2 = max(maxx2, odd[i]);
            }

            int counter = 0;

            for (int i = 0; i < odd.size(); i++) {
                if (odd[i] == maxx2) {
                    counter++;
                    continue;
                }
                else {
                    count1 += odd[i] - 1;
                }
            }

            count1 += (counter - 1) * (maxx2 - 1);
        }

        return maxx2 + count + count1;
    }
};