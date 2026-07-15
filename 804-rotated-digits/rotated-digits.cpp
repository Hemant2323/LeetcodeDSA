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
               // vector<int> r;
                 bool invalid = false, change = false;
                while (x > 0) {
                    int rem = x % 10;
                   
                    //  r.push_back(rem);
                    if (rem == 2 || rem == 5 || rem == 6 || rem == 9) {
                        change = true;
                    }
                    if (rem == 3 || rem == 4 || rem == 7) {
                        invalid = true;
                        break;
                    }

                   

                    x /= 10;
                }
                 if (!invalid && change) {
                        count++;
                    }
                // bool invalid = false, change = false;
                // for (int j = 0; j < r.size(); j++) {
                //     if (r[j] == 2 || r[j] == 5 || r[j] == 6 || r[j] == 9) {
                //         change = true;
                //     }
                //     if (r[j] == 3 || r[j] == 4 || r[j] == 7) {
                //         invalid = true;
                //         break;
                //     }
                // }

                // if(!invalid && change){
                //     count++;
                // }
            }
        }
        return count;
    }
};