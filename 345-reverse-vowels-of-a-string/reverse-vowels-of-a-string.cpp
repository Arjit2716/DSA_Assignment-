class Solution {
public:
    bool isVowel(char c) {
        c = tolower(c);
        return c=='a' || c=='e' || c=='i' || c=='o' || c=='u';
    }

    string reverseVowels(string s) {
        vector<char> vowels;

        // Store vowels
        for(char c : s) {
            if(isVowel(c))
                vowels.push_back(c);
        }

        int j = vowels.size() - 1;

        // Replace vowels in reverse order
        for(int i = 0; i < s.size(); i++) {
            if(isVowel(s[i])) {
                s[i] = vowels[j--];
            }
        }

        return s;
    }
};