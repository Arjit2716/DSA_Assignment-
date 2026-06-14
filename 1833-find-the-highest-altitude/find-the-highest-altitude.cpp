class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int alt=0;
        int maxalt=0;

        for(int num:gain){
            alt+=num;
            maxalt=max(maxalt,alt);
        }
        return maxalt;
    }
};