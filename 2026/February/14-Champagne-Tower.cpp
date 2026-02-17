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
    double champagneTower(int poured, int r, int c)
    {
        vector<vector<double>> dp(105, vector<double>(105, 0.0));
        dp[0][0] = (double)poured;
        for (int i = 0; i <= r; i++)
        {
            for (int j = 0; j <= r; j++)
            {
                if (dp[i][j] > 1.0)
                {
                    double flood = (dp[i][j] - 1.0) / 2.00;
                    dp[i + 1][j] += flood;
                    dp[i + 1][j + 1] += flood;
                    dp[i][j] = 1.0;
                }
            }
        }

        return dp[r][c];
    }
};