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
    long long largestSquareArea(vector<vector<int>> &bot, vector<vector<int>> &top)
    {
        int n = top.size();
        ll maxArea = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                int l = max(bot[i][0], bot[j][0]);
                int r = min(top[i][0], top[j][0]);
                int u = min(top[i][1], top[j][1]);
                int d = max(bot[i][1], bot[j][1]);

                int hlen = r - l, vlen = u - d;
                if (hlen > 0 && vlen > 0)
                {
                    ll mnlen = min(vlen, hlen);
                    maxArea = max(maxArea, mnlen * mnlen);
                }
            }
        }

        return maxArea;
    }
};