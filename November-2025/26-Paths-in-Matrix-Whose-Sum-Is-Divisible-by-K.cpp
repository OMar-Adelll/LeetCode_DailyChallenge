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
    int Mod = 1000000007;
    int safe_mod(int x, int y, int k) { return (((x - y) % k) + k) % k; }
    int numberOfPaths(vector<vector<int>> &grid, int k)
    {
        int n = grid.size(), m = grid[0].size();
        vector<vector<vector<long long>>> dp(
            n, vector<vector<long long>>(m, vector<long long>(k, 0)));
        dp[0][0][grid[0][0] % k] = 1;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                for (int rem = 0; rem < k; rem++)
                {
                    if (i - 1 >= 0)
                        dp[i][j][rem] +=
                            dp[i - 1][j][safe_mod(rem, grid[i][j], k)];
                    if (j - 1 >= 0)
                        dp[i][j][rem] +=
                            dp[i][j - 1][safe_mod(rem, grid[i][j], k)];

                    dp[i][j][rem] %= Mod;
                }
            }
        }
        return dp[n - 1][m - 1][0];
    }
};