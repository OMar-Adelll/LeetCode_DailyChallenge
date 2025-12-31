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
    vector<int> dx{0, 0, -1, 1};
    vector<int> dy{-1, 1, 0, 0};

public:
    int n, m;
    vector<vector<int>> H;
    vector<vector<bool>> Atlantic, Pacific;
    bool is_valid(int i, int j)
    {
        return (i >= 0 && j >= 0 && i < n && j < m);
    }

    void dfs(int i, int j, vector<vector<bool>> &Ocean, int prv)
    {
        if (!is_valid(i, j) || H[i][j] < prv || Ocean[i][j])
            return;
        Ocean[i][j] = true;
        for (int d = 0; d < 4; d++)
        {
            int nx = i + dx[d], ny = j + dy[d];
            dfs(nx, ny, Ocean, H[i][j]);
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>> &h)
    {
        H = h;
        n = sz(h), m = sz(h[0]);
        Atlantic.assign(n, vector<bool>(m, false)), Pacific.assign(n, vector<bool>(m, false));
        vector<vector<int>> res;

        for (int i = 0; i < n; i++)
        {
            // edges -> {i, 0} , {i, m-1};
            dfs(i, 0, Pacific, H[i][0]);
            dfs(i, m - 1, Atlantic, H[i][m - 1]);
        }

        for (int j = 0; j < m; j++)
        {
            // edges -> {0, j} , {n -1, j}
            dfs(0, j, Pacific, H[0][j]);
            dfs(n - 1, j, Atlantic, H[n - 1][j]);
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (Pacific[i][j] && Atlantic[i][j])
                    res.push_back({i, j});
            }
        }

        return res;
    }
};