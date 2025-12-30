// بسم الله الرحمن الرحيم
//  وَأَنْ لَيْسَ لِلْإِنسَانِ إِلَّا مَا سَعَىٰ
//  Free Palestine
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define all(vec) (vec).begin(), (vec).end()
#define sz(x) (int)(x).size()
#define i(x) (x - 'a')
#define updmax(a, x) (a = max((a), (x)))
#define updmin(a, x) (a = min((a), (x)))
#define nl '\n'

class Solution
{
public:
    int numMagicSquaresInside(vector<vector<int>> &grid)
    {
        int n = grid.size(), m = grid[0].size();
        if (n < 3 || m < 3)
            return 0;

        int cnt = 0;
        for (int i = 0; i + 2 < n; i++)
        {
            for (int j = 0; j + 2 < m; j++)
            {

                vector<bool> vis(10, false);
                bool goo = true;
                for (int idx = i; idx < i + 3; idx++)
                {
                    bool go = true;
                    for (int jdx = j; jdx < j + 3; jdx++)
                    {
                        int x = grid[idx][jdx];
                        if (x < 1 || x > 9 || vis[x])
                        {
                            go = false;
                            break;
                        }
                        vis[x] = true;
                    }
                    if (!go)
                    {
                        goo = false;
                        break;
                    }
                }

                if (!goo)
                    continue;

                int r1 = grid[i][j] + grid[i][j + 1] + grid[i][j + 2];
                int r2 = grid[i + 1][j] + grid[i + 1][j + 1] + grid[i + 1][j + 2];
                int r3 = grid[i + 2][j] + grid[i + 2][j + 1] + grid[i + 2][j + 2];

                int c1 = grid[i][j] + grid[i + 1][j] + grid[i + 2][j];
                int c2 = grid[i][j + 1] + grid[i + 1][j + 1] + grid[i + 2][j + 1];
                int c3 = grid[i][j + 2] + grid[i + 1][j + 2] + grid[i + 2][j + 2];

                int dig1 = grid[i][j] + grid[i + 1][j + 1] + grid[i + 2][j + 2];
                int dig2 = grid[i][j + 2] + grid[i + 1][j + 1] + grid[i + 2][j];

                if (r1 == r2 && r2 == r3 && r1 == c1 && c1 == c2 && c2 == c3 && dig1 == dig2)
                    cnt++;
            }
        }

        return cnt;
    }
};