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

#define f first
#define s second
class Solution
{
public:
    int countCoveredBuildings(int n, vector<vector<int>> &a)
    {
        map<int, pair<int, int>> xs, ys;
        for (int i = 0; i < a.size(); i++)
        {
            int x = a[i][0], y = a[i][1];
            if (!xs.count(y))
            {
                xs[y] = {x, x};
            }
            else
            {
                xs[y].f = min(xs[y].f, x);
                xs[y].s = max(xs[y].s, x);
            }

            if (!ys.count(x))
            {
                ys[x] = {y, y};
            }
            else
            {
                ys[x].f = min(ys[x].f, y);
                ys[x].s = max(ys[x].s, y);
            }
        }

        int cnt = 0;
        for (int i = 0; i < a.size(); i++)
        {
            int x = a[i][0], y = a[i][1];

            int dow = ys[x].f;
            int up = ys[x].s;

            int lef = xs[y].f;
            int rig = xs[y].s;

            if (dow < y && up > y && lef < x && rig > x)
                cnt++;
        }

        return cnt;
    }
};