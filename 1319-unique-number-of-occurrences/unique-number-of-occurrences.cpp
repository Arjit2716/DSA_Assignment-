class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int>mp;
        for(int x:arr){
            mp[x]++;
        }
        unordered_set<int>x;
        for(auto p:mp){
            if(x.count(p.second)) return false;

            x.insert(p.second);
        }
        return true;
    }
};