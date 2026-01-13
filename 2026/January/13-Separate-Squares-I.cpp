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

#define ld long double
class Solution
{
public:
    double separateSquares(vector<vector<int>> &sq)
    {
        int n = sq.size();

        auto can = [&](ld mid) -> ld
        {
            ld above = 0, below = 0;
            for (int i = 0; i < n; i++)
            {
                ld x = sq[i][0], y = sq[i][1], len = sq[i][2];
                if (mid <= y)
                {
                    above += (len * len);
                }
                else if (mid >= y + len)
                {
                    below += (len * len);
                }
                else
                {
                    ld h = mid - y;
                    ld area = h * len;
                    ld rm = (len * len) - area;
                    below += area;
                    above += rm;
                }
            }

            return above - below;
        };

        ld l = 0, r = 1e12, ans = 0;
        int M = 300;
        while (M--)
        {
            ld mid = (ld)(l + r) / 2.00;
            if (can(mid) > 0)
                ans = mid, l = mid;
            else
                r = mid;
        }

        return ans;
    }
};