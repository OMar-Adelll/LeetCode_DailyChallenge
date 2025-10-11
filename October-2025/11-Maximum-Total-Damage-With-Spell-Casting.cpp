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
    vector<ll> dp;
    vector<pair<ll, ll>> ans;
    ll rec(int i)
    {
        int n = sz(ans);
        if (i >= n)
            return 0;

        if (dp[i] != -1)
            return dp[i];

        ll leave = rec(i + 1);
        int j = i + 1;
        while (j < n && ans[j].first <= ans[i].first + 2)
            j++;

        ll take = ans[i].second + rec(j);

        dp[i] = max(take, leave);
        return dp[i];
    }
    long long maximumTotalDamage(vector<int> &power)
    {
        int n = sz(power);
        sort(all(power));
        for (int i = 0; i < n; i++)
        {
            ll cur = power[i], sum = 0;
            while (i < n && power[i] == cur)
                sum += cur, i++;

            ans.push_back({cur, sum});
            i--;
        }

        dp.assign(sz(ans), -1);
        return rec(0);
    }
};