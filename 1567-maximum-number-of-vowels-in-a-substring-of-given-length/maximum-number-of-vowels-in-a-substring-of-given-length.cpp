class Solution {
public:

bool isvowel(char c){
    c=tolower(c);
    return c=='a'||c=='e'||c=='i'||c=='o'||c=='u';
}
    int maxVowels(string s, int k) {
       int n=s.size();
       int cnt=0;
        
        for(int i=0;i<k;i++){
            if(isvowel(s[i])) cnt++;
        }
        int maxcnt=cnt;
        for(int i=k;i<n;i++){
            if(isvowel(s[i]))
            cnt++;

            if(isvowel(s[i-k])) cnt--;
            maxcnt=max(maxcnt,cnt);
        }
        return maxcnt;
    }
};