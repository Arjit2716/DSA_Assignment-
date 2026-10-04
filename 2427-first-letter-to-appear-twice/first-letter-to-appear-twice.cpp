class Solution {
public:
    char repeatedCharacter(string s) {
        int n=s.size();
        if(n==0) return 0;

        unordered_map<char,int>freq;
        for(char c:s){
            freq[c]++;

            if(freq[c]==2) return c;
        }

        return 0;
    }
};