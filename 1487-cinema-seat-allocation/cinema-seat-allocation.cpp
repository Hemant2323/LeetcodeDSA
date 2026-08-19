class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        sort(reservedSeats.begin(), reservedSeats.end());
        int count = 0;

        map<int, vector<int>> mp;
        for (auto& x : reservedSeats) {
            mp[x[0]].push_back(x[1]);
        }

        // vector<int> hash(n + 1, 0);

        // for (auto& x : mp) {
        //     hash[x.first]++;
        // }
        // for (int i = 1; i < hash.size(); i++) {
        //     if (hash[i] == 0) {
        //         count += 2;
        //     }
        // }
        int x=mp.size();
        int diff=n-x;

        count+=diff*2;

        for (auto& x : mp) {
            vector<int> arr = x.second;
            vector<int> hash(11, 0);
            for (int i = 0; i < arr.size(); i++) {
                hash[arr[i]]++;
            }
            if (hash[2] == 0 && hash[3] == 0 && hash[4] == 0 && hash[5] == 0) {
                count++;
                hash[2] = 1;
                hash[3] = 1;
                hash[4] = 1;
                hash[5] = 1;
            }
            if (hash[4] == 0 && hash[5] == 0 && hash[6] == 0 && hash[7] == 0) {
                count++;
                hash[4] = 1;
                hash[5] = 1;
                hash[6] = 1;
                hash[7] = 1;
            }
            if (hash[6] == 0 && hash[7] == 0 && hash[8] == 0 && hash[9] == 0) {
                count++;
                hash[6] = 1;
                hash[7] = 1;
                hash[8] = 1;
                hash[9] = 1;
            }
        }

        return count;
    }
};