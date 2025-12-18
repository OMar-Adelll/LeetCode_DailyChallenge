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

#define ll long long
class Solution
{
public:
    long long maxProfit(vector<int> &p, vector<int> &st, int k)
    {
        int n = p.size();
        vector<ll> product(n + 1), prefix(n + 1);
        for (int i = 1; i <= n; i++)
            prefix[i] = prefix[i - 1] + p[i - 1], product[i] = product[i - 1] + p[i - 1] * st[i - 1];

        ll ans = product[n];
        for (int i = k - 1; i < n; i++)
        {
            ll L = product[i - k + 1];
            ll R = product[n] - product[i + 1];
            ll dif = prefix[i + 1] - prefix[i - (k / 2) + 1];
            ans = max(ans, L + R + dif);
        }

        return ans;
    }
};