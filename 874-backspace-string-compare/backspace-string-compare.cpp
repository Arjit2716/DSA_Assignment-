class Solution {

    public:
    string build (string str){
        string s;
        for(char c:str){
            if(c=='#'){
                if(!s.empty()) s.pop_back();
            }
            else s.push_back(c);
        }
        return s;
    }
    bool backspaceCompare(string s, string t) {
        return build(s)==build(t);
    }

};