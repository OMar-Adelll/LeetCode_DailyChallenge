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
    int minTimeToVisitAllPoints(vector<vector<int>> &points)
    {
        int cnt = 0;
        int curx = points[0][0], cury = points[0][1];
        for (int i = 1; i < points.size(); i++)
        {
            int x = abs(curx - points[i][0]);
            int y = abs(cury - points[i][1]);
            cnt += max(x, y);
            curx = points[i][0], cury = points[i][1];
        }

        return cnt;
    }
};