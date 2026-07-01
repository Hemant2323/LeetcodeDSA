class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extra) {
        vector<bool>res(candies.size(),false);
        int mx=*max_element(candies.begin(),candies.end());
        for(int i=0;i<candies.size();i++){
            if(candies[i]+extra>=mx){
                res[i]=true;
            }
            
        }
        return res;
    }
};