class Solution {
public:
    string decodeString(string s) {
        stack<int>cnt;
        stack<string>st;

        int num=0;
        string curr="";

        for(char ch:s){
            if(isdigit(ch)) num=num*10+(ch-'0');
            else if(ch=='['){
                cnt.push(num);
                st.push(curr);

                num = 0;      // Reset number
            curr = ""; 
            }

            else if(ch==']'){
                int k=cnt.top();
                cnt.pop();

                string prev=st.top();
                st.pop();

                string ans="";

                for(int i=0;i<k;i++){
                    ans+=curr;
                }
                curr=prev+ans;
            }
            else curr+=ch;
        }
        return curr;
    }
};