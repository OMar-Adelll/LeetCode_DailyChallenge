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
    int largestMagicSquare(vector<vector<int>> &grid)
    {
        int N = grid.size(), M = grid[0].size(), Min = min(N, M);
        int MaxArea = 1;
        for (int MagicSz = 2; MagicSz <= min(N, M); MagicSz++)
        {
            for (int I = 0; I + MagicSz - 1 < N; I++)
            {
                for (int J = 0; J + MagicSz - 1 < M; J++)
                {

                    int n = I + MagicSz, m = J + MagicSz;
                    int def = -1;
                    bool notMagic = false;

                    for (int i = I; i < n; i++)
                    {
                        int sum = 0;

                        for (int j = J; j < m; j++)
                        {
                            sum += grid[i][j];
                        }
                        if (def == -1)
                        {
                            def = sum;
                        }
                        else if (def != sum)
                        {
                            notMagic = true;
                            break;
                        }
                    }

                    if (notMagic)
                        continue;

                    for (int j = J; j < m; j++)
                    {
                        int sum = 0;
                        for (int i = I; i < n; i++)
                        {
                            sum += grid[i][j];
                        }

                        if (sum != def)
                        {
                            notMagic = true;
                            break;
                        }
                    }

                    if (notMagic)
                        continue;

                    int dig1 = 0, dig2 = 0;
                    for (int i = 0; i < MagicSz; i++)
                    {
                        dig1 += grid[i + I][i + J];
                        dig2 += grid[i + I][J + MagicSz - i - 1];
                    }

                    if (dig1 != def || dig2 != def)
                        continue;

                    MaxArea = max(MaxArea, MagicSz);
                }
            }
        }
        return MaxArea;
    }
};
