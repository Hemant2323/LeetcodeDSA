class Solution {
public:
    int maxProduct(int n) {
        int ans;
        // int maxx=1;
        // while(n>0){
        //     int x=n%10;
        //     maxx=max(maxx,x);
        //     n/=10;
        // }
        string s=to_string(n);
        sort(s.begin(),s.end());
        int x=s.size();
        return (s[x-1]-'0')*(s[x-2]-'0');

    }
};