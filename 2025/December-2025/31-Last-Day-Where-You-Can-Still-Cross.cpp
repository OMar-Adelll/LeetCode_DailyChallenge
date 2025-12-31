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
private:
    const int dx[4] = {-1, 1, 0, 0};
    const int dy[4] = {0, 0, 1, -1};

    bool valid(int r, int c, int n, int m)
    {
        return (r >= 0 && c >= 0 && r < n && c < m);
    }

    bool canreach(int mid, int n, int m, vector<vector<int>> &time)
    {

        queue<pair<int, int>> q;
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        vector<vector<int>> grid(n, vector<int>(m, 0));
        for (int i = 0; i < mid; i++)
        {
            int tx = time[i][0] - 1;
            int ty = time[i][1] - 1;
            grid[tx][ty] = 1;
        }

        for (int i = 0; i < m; i++)
        {
            if (grid[0][i] == 0)
            {
                q.push({0, i}), vis[0][i] = 1;
            }
        }

        while (!q.empty())
        {
            auto [x, y] = q.front();
            q.pop();
            if (x == n - 1)
                return true;

            for (int d = 0; d < 4; d++)
            {
                int nx = x + dx[d];
                int ny = y + dy[d];

                if (valid(nx, ny, n, m) && !vis[nx][ny] && grid[nx][ny] == 0)
                {
                    q.push({nx, ny});
                    vis[nx][ny] = true;
                }
            }
        }

        return false;
    };

public:
    int latestDayToCross(int n, int m, vector<vector<int>> &t)
    {
        int lasttime = 0;

        int l = 0, r = sz(t) - 1, ans;
        while (l <= r)
        {
            int midTime = (l + r) / 2;
            if (canreach(midTime, n, m, t))
                ans = midTime, l = midTime + 1;
            else
                r = midTime - 1;
        }

        return ans;
    }
};
