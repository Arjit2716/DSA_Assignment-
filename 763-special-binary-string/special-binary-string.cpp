class Solution {
public:
    string makeLargestSpecial(string s) {
        int n=s.size();
       vector<string>res;
       int cnt=0;
       int start=0;
       for(int i=0;i<n;i++){
        if(s[i]=='1') cnt++;
        else cnt--;

        if(cnt==0){
            string inner=makeLargestSpecial(s.substr(start+1,i-start-1));
            res.push_back("1"+inner+"0");
            start=i+1; 
              }    
       }
       sort(res.begin(),res.end(),greater<string>());
       string ans="";
       for(auto &str:res) ans+=str;
       return ans;
    }
};