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
    bool can(ll mid, vector<ll> &pw, ll r, ll k)
    {
        ll n = sz(pw);
        vector<ll> add(n, 0);
        ll extra = 0, rm = k;
        for (int i = 0; i < n; i++)
        {
            if (i - r - 1 >= 0)
                extra -= add[i - r - 1];

            ll cur = pw[i] + extra;
            if (cur < mid)
            {
                ll need = mid - cur;
                if (need > rm)
                    return false;

                rm -= need;
                int idx = min(n - 1, i + r);
                add[idx] += need;
                extra += need;
            }
        }

        return true;
    }

    long long maxPower(vector<int> &nums, int r, int k)
    {
        int n = sz(nums);
        vector<ll> pre(n + 1), pw(n);
        for (int i = 1; i <= n; i++)
            pre[i] = pre[i - 1] + nums[i - 1];

        for (int i = 0; i < n; i++)
        {
            int L = max(0, i - r);
            int R = min(n - 1, i + r);
            pw[i] = pre[R + 1] - pre[L]; // -> because I'm started when i = 0  
        }

        ll L = 0, R = 1e14, ans = 0;
        while (L <= R)
        {
            ll mid = (L + R) / 2;
            if (can(mid, pw, r, k))
                ans = mid, L = mid + 1;
            else
                R = mid - 1;
        }

        return ans;
    }
};