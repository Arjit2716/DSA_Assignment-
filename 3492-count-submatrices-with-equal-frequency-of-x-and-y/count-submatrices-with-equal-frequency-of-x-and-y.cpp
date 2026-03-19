class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int count = 0;

        vector<vector<int>> sum(m, vector<int>(n, 0));
        vector<vector<int>> cntX(m, vector<int>(n, 0));

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {

                sum[i][j] = (grid[i][j] == 'X') ? 1 : (grid[i][j] == 'Y' ? -1 : 0);
                cntX[i][j] = (grid[i][j] == 'X');

                if(i > 0) {
                    sum[i][j] += sum[i-1][j];
                    cntX[i][j] += cntX[i-1][j];
                }
                if(j > 0) {
                    sum[i][j] += sum[i][j-1];
                    cntX[i][j] += cntX[i][j-1];
                }
                if(i > 0 && j > 0) {
                    sum[i][j] -= sum[i-1][j-1];
                    cntX[i][j] -= cntX[i-1][j-1];
                }

                if(sum[i][j] == 0 && cntX[i][j] > 0)
                    count++;
            }
        }

        return count;
    }
};