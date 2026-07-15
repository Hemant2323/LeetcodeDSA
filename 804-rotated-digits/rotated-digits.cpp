class Solution {
public:
    int rotatedDigits(int n) {
        int count = 0;
        if (n <= 10) {
            for (int i = 0; i <= n; i++) {
                if (i == 2 || i == 5 || i == 6 || i == 9) {
                    count++;
                }
            }
        } else {
            for (int i = 0; i <= n; i++) {
                int x = i;
                vector<int> r;
                while (x > 0) {
                    int rem = x % 10;
                    r.push_back(rem);

                    x /= 10;
                }
                bool invalid = false, change = false;
                for (int j = 0; j < r.size(); j++) {
                    if (r[j] == 2 || r[j] == 5 || r[j] == 6 || r[j] == 9) {
                        change = true;
                    }
                    if (r[j] == 3 || r[j] == 4 || r[j] == 7) {
                        invalid = true;
                        break;
                    }
                }

                if(!invalid && change){
                    count++;
                }
            }
        }
        return count;
    }
};