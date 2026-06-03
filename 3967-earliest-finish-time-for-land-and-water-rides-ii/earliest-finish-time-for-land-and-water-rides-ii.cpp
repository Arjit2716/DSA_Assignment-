class Solution {
public:
    long long query(vector<int>& start,
                    vector<int>& prefMinDur,
                    vector<long long>& suffMin,
                    long long x) {

        int pos = upper_bound(start.begin(), start.end(), x) - start.begin();

        long long ans = LLONG_MAX;

        if (pos > 0)
            ans = min(ans, x + prefMinDur[pos - 1]);

        if (pos < start.size())
            ans = min(ans, suffMin[pos]);

        return ans;
    }

    int earliestFinishTime(vector<int>& landStartTime,
                           vector<int>& landDuration,
                           vector<int>& waterStartTime,
                           vector<int>& waterDuration) {

        int n = landStartTime.size();
        int m = waterStartTime.size();

        vector<pair<int,int>> land(n), water(m);

        for(int i=0;i<n;i++)
            land[i]={landStartTime[i], landDuration[i]};

        for(int i=0;i<m;i++)
            water[i]={waterStartTime[i], waterDuration[i]};

        sort(land.begin(), land.end());
        sort(water.begin(), water.end());

        vector<int> landS(n), landD(n);
        vector<int> waterS(m), waterD(m);

        for(int i=0;i<n;i++){
            landS[i]=land[i].first;
            landD[i]=land[i].second;
        }

        for(int i=0;i<m;i++){
            waterS[i]=water[i].first;
            waterD[i]=water[i].second;
        }

        vector<int> prefLand(n), prefWater(m);

        prefLand[0]=landD[0];
        for(int i=1;i<n;i++)
            prefLand[i]=min(prefLand[i-1], landD[i]);

        prefWater[0]=waterD[0];
        for(int i=1;i<m;i++)
            prefWater[i]=min(prefWater[i-1], waterD[i]);

        vector<long long> suffLand(n), suffWater(m);

        suffLand[n-1]=1LL*landS[n-1]+landD[n-1];
        for(int i=n-2;i>=0;i--)
            suffLand[i]=min(suffLand[i+1],
                            1LL*landS[i]+landD[i]);

        suffWater[m-1]=1LL*waterS[m-1]+waterD[m-1];
        for(int i=m-2;i>=0;i--)
            suffWater[i]=min(suffWater[i+1],
                             1LL*waterS[i]+waterD[i]);

        long long ans = LLONG_MAX;

        // Land -> Water
        for(int i=0;i<n;i++){
            long long endLand =
                1LL*landStartTime[i] + landDuration[i];

            ans = min(ans,
                      query(waterS,
                            prefWater,
                            suffWater,
                            endLand));
        }

        // Water -> Land
        for(int j=0;j<m;j++){
            long long endWater =
                1LL*waterStartTime[j] + waterDuration[j];

            ans = min(ans,
                      query(landS,
                            prefLand,
                            suffLand,
                            endWater));
        }

        return (int)ans;
    }
};