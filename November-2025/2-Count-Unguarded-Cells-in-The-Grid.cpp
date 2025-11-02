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
    const int dx[4] = {-1, 1, 0, 0};
    const int dy[4] = {0, 0, -1, 1};

public:
    int countUnguarded(int n, int m, vector<vector<int>> &guards, vector<vector<int>> &walls)
    {
        vector<vector<int>> matrix(n, vector<int>(m, 0));
        for (int i = 0; i < sz(walls); i++)
        {
            int x = walls[i][0], y = walls[i][1];
            matrix[x][y] = 10;
        }

        for (int i = 0; i < sz(guards); i++)
        {
            int x = guards[i][0], y = guards[i][1];
            matrix[x][y] = 10;
        }

        for (int i = 0; i < sz(guards); i++)
        {
            int x = guards[i][0], y = guards[i][1];

            for (int i = 0; i < 4; i++)
            {
                int nx = dx[i] + x, ny = dy[i] + y;
                while (nx >= 0 && nx < n && ny >= 0 && ny < m && matrix[nx][ny] != 10)
                {
                    matrix[nx][ny] = 5;
                    nx += dx[i];
                    ny += dy[i];
                }
            }
        }

        int cnt = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cnt += (!matrix[i][j]);

        return cnt;
    }
};
