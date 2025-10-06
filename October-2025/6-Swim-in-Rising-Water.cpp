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

struct point
{
    int x, y, val;
    bool operator>(const point &t2) const
    {
        return val > t2.val;
    }
};
vector<int> dx = {0, 0, -1, 1};
vector<int> dy = {-1, 1, 0, 0};

class Solution
{
public:
    int swimInWater(vector<vector<int>> &grid)
    {
        int n = sz(grid);
        auto valid = [&](int i, int j) -> bool
        {
            return (i >= 0 && i < n && j >= 0 && j < n);
        };

        vector<vector<bool>> vis(n, vector<bool>(n, false));
        priority_queue<point, vector<point>, greater<point>> q;
        q.push({0, 0, grid[0][0]});
        int dis = 0;
        while (!q.empty())
        {
            auto fr = q.top();
            q.pop();
            if (vis[fr.x][fr.y])
                continue;

            vis[fr.x][fr.y] = true;
            updmax(dis, fr.val);

            if (fr.x == n - 1 and fr.y == n - 1)
                return dis;

            for (int d = 0; d < 4; d++)
            {
                int nx = fr.x + dx[d], ny = fr.y + dy[d];
                if (valid(nx, ny) && !vis[nx][ny])
                    q.push({nx, ny, grid[nx][ny]});
            }
        }

        return -1;
    }
};