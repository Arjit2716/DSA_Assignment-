class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        map<char,int>mr;
        map<char,int>mm;
        int m=ransomNote.size();
        int n=magazine.size();

        for(int i=0;i<m;i++){
            mr[ransomNote[i]]++;
        }

        for(int i=0;i<n;i++){
            mm[magazine[i]]++;
        }


for(auto x:mr){
    if(mm[x.first]<x.second)
    return false;
}

return true;
    }
};