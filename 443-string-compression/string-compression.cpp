class Solution {
public:
    int compress(vector<char>& chars) {
        queue<char>q;

        for(char ch:chars){
            q.push(ch);
        }
        string ans="";
        while(!q.empty()){
           char curr =q.front();
            q.pop();

            int cnt=1;
            while(!q.empty()&&q.front()==curr){
                cnt++;

                q.pop();
            }
            ans+=curr;
// here i just count the frequency of the array
            if(cnt>1){
                ans+= to_string(cnt);
            }
            for(int i=0;i<ans.size();i++){
                chars[i]=ans[i];
            }
        }
        return ans.size();
    }
};