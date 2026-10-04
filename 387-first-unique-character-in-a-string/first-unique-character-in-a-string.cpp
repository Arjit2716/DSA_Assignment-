class Solution {
public:
    int firstUniqChar(string s) {

        int n=s.size();
        if(n==0) return 0;
        int freq[26]={0};

        for(char c:s){
            freq[c-'a']++;
        }

        for(int i=0;i<n;i++){
           if(freq[s[i]-'a']==1) return i; 
        }

        return -1;
    }
};