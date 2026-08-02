class Solution {
public:
    vector<string> removeComments(vector<string>& source) {
        vector<string> res;
        int index=0;
        string temp="";
        bool cmmnt=false;
        int n=source.size();
        for(int i=0;i<n;i++){
            int x=source[i].size();

            for(int j=0;j<x;j++){
                if(!cmmnt && j+1<source[i].size() && source[i][j]=='/' && source[i][j+1]=='/'){
                    break;
                }
                else if(!cmmnt && j+1<source[i].size() && source[i][j]=='/' && source[i][j+1]=='*'){
                    cmmnt=true;
                    j++;

                }
                else if(cmmnt && j+1<source[i].size() && source[i][j]=='*' && source[i][j+1]=='/'){
                    cmmnt=false;
                    j++;
                }
                else if(!cmmnt){
                    temp+=source[i][j];
                }


                
            }
            if(!cmmnt && !temp.empty()){
                res.push_back(temp);
                temp="";
            }
        }
        return res;
    }
};