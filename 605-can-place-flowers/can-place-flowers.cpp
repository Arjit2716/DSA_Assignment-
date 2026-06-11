// class Solution {
// public:
//     bool canPlaceFlowers(vector<int>& flowerbed, int n) {
//         int cnt0=0;
//         int cnt1=0+n;
//         for (int i = 0; i < flowerbed.size(); i++) {
//         if(flowerbed[i]==0) cnt0++;
//         if(flowerbed[i]==1) cnt1++;
//         }
//         if(cnt0==cnt1) return true;
//         else return false;
//     }
// };

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int count = 0;

        for(int i = 0; i < flowerbed.size(); i++) {
            if(flowerbed[i] == 0) {
                bool left = (i == 0) || (flowerbed[i - 1] == 0);
                bool right = (i == flowerbed.size() - 1) || (flowerbed[i + 1] == 0);

                if(left && right) {
                    flowerbed[i] = 1;
                    count++;
                }
            }
        }

        return count >= n;
    }
};