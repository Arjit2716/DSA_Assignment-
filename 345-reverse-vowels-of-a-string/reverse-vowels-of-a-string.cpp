class Solution {
public:

bool isvowel(char c){
    c=tolower(c);
    return c=='a'||c=='e'||c=='i'||c=='o'||c=='u';
}
    string reverseVowels(string s) {
        int n=s.size();

        int l=0;
        int r=n-1;

        while(l<r){
            while(l<r&&!isvowel(s[l])) l++;
            while(l<r&&!isvowel(s[r])) r--;

            if(l<r){
                swap(s[l],s[r]);
                l++;
                r--;
            }

         }
          return s;
    }
};