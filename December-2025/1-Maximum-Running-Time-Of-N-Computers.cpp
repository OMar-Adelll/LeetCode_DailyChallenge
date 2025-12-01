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
    long long maxRunTime(int n, vector<int> &bat)
    {
        auto can = [&](ll mid)
        {
            ll sum = 0;
            for (auto &c : bat)
                sum += min(mid, (ll)c);

            return sum / n >= mid;
        };

        ll l = 0, r = 1e18, ans = 0;
        while (l <= r)
        {
            ll mid = (l + r) / 2;
            if (can(mid))
                ans = mid, l = mid + 1;
            else
                r = mid - 1;
        }

        return ans;
    }
};