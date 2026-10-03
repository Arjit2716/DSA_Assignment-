class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int minpro=prices[0];
        int maxpro=0;
        for(int i=0;i<n;i++){

            int cost=prices[i]-minpro;

            maxpro=max(maxpro,cost);

            minpro=min(minpro,prices[i]);
            
        }
        return maxpro;

    }
};