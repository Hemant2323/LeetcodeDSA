class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int maxx=*max_element(nums.begin(),nums.end());
         int minn=*min_element(nums.begin(),nums.end());
        vector<int> hash(maxx+1,0);
        for(int i=0;i<nums.size();i++){
            hash[nums[i]]++;
        }
        vector<int>res;
        for(int i=minn;i<hash.size();i++){
            if(hash[i]==0){
                res.push_back(i);
            }
        }
        return res;

    }
};