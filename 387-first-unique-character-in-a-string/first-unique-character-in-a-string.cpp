class Solution {
public:
    int firstUniqChar(string s) {
        int n=s.size();
        if(n==0) return 0;
        unordered_map<char,int>freq;

        for(char c:s){
            freq[c]++;
        }

        for(int i=0;i<n;i++){
            if(freq[s[i]]==1) return i;
        }
        return -1;
    }
};