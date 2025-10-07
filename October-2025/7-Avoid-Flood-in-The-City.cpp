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
    vector<int> avoidFlood(vector<int> &rains)
    {
        int n = sz(rains);
        vector<int> ans(n, -1);
        set<int> ze;
        map<int, int> ld;

        for (int i = 0; i < n; i++)
        {
            int x = rains[i];
            if (x > 0)
            {
                if (ld.count(x))
                {
                    int d = ld[x];
                    auto it = ze.upper_bound(d);

                    if (it == ze.end())
                        return {};

                    int dry = *it;
                    ans[dry] = x;
                    ze.erase(it);
                }
                ld[x] = i;
            }
            else
            {
                ans[i] = 1;
                ze.insert(i);
            }
        }

        return ans;
    }
};