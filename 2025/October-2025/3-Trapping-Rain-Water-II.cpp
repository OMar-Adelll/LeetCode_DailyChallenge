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

struct node
{
    int x, y, v;
    bool operator<(const node &t) const
    {
        return v > t.v;
    }
};
vector<int> dx = {0, 0, -1, 1};
vector<int> dy = {-1, 1, 0, 0};

class Solution
{
public:
    int trapRainWater(vector<vector<int>> &Map)
    {
        int n = sz(Map), m = sz(Map[0]);
        priority_queue<node> pq;
        vector<vector<bool>> vis(n, vector<bool>(m, 0));
        auto is_border = [&](int i, int j)
        {
            return (i == 0) or (j == 0) or (i == n - 1) or (j == m - 1);
        };

        auto valid = [&](int i, int j)
        {
            return (i >= 0) and (i < n) and (j >= 0) and (j < m);
        };

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (is_border(i, j))
                {
                    pq.push({i, j, Map[i][j]});
                    vis[i][j] = 1;
                }
            }
        }

        int rs = 0;
        while (!pq.empty())
        {
            auto T = pq.top();
            pq.pop();
            for (int i = 0; i < 4; i++)
            {
                int nx = T.x + dx[i];
                int ny = T.y + dy[i];
                int nv = -1;
                if (valid(nx, ny) and !vis[nx][ny])
                {
                    nv = max(T.v, Map[nx][ny]);
                    vis[nx][ny] = 1;
                    pq.push({nx, ny, nv});
                    rs += nv - Map[nx][ny];
                }
            }
        }

        return rs;
    }
};