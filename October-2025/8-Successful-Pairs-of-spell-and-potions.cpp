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
    vector<int> successfulPairs(vector<int> &spells, vector<int> &potions, ll suc)
    {
        int n = sz(spells), m = sz(potions);
        sort(all(potions));
        vector<int> ans(n);
        for (int i = 0; i < n; i++)
        {
            ll x = spells[i];
            int l = 0, r = m - 1, rs = 1e9;
            while (l <= r)
            {
                int mid = (l + r) / 2;
                ll pro = potions[mid] * x;
                if (pro >= suc)
                {
                    updmin(rs, mid);
                    r = mid - 1;
                }
                else
                {
                    l = mid + 1;
                }
            }
            int len;
            if (rs >= m)
                len = 0;
            else
                len = m - rs;
            ans[i] = len;
        }
        return ans;
    }
};
