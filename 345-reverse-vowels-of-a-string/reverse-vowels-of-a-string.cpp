class Solution {
public:

bool isVowel(char c){
    c=tolower(c);
    return c=='a'||c=='e'||c=='i'||c=='o'||c=='u';

}
    string reverseVowels(string s) {
        int n=s.size();
        stack<char>st;
     for(char c:s){
        if(isVowel(c)) st.push(c);
     }
     for(int i=0;i<n;i++){
        if(isVowel(s[i])){
        s[i]=st.top();
        st.pop();
        }
     }
     return s;
    }
};