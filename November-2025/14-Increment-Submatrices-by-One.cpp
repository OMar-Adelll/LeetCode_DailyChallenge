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
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>> &queries)
    {
        vector<vector<int>> par(n + 2, vector<int>(n + 2));
        for (auto &p : queries)
        {
            int r1 = p[0] + 1;
            int c1 = p[1] + 1;
            int r2 = p[2] + 1;
            int c2 = p[3] + 1;

            par[r1][c1] += 1;
            par[r1][c2 + 1] -= 1;
            par[r2 + 1][c1] -= 1;
            par[r2 + 1][c2 + 1] += 1;
        }

        vector<vector<int>> prefix(n + 2, vector<int>(n + 2));
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                prefix[i][j] = prefix[i - 1][j] + prefix[i][j - 1] - prefix[i - 1][j - 1] + par[i][j];

        vector<vector<int>> ans(n, vector<int>(n));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                ans[i][j] = prefix[i + 1][j + 1];

        return ans;
    }
};