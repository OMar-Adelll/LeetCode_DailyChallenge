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
    const int Mod = 1000000007;

public:
    int specialTriplets(vector<int> &nums)
    {
        map<int, int> l, r;
        for (auto &c : nums)
            r[c]++;
        long long cnt = 0;
        for (auto &val : nums)
        {
            r[val]--;
            int x = 2 * val;

            long long cnt1 = 0;
            if (l.find(x) != l.end())
                cnt1 = l[x];

            long long cnt2 = 0;
            if (r.find(x) != r.end())
                cnt2 = r[x];

            cnt = (cnt % Mod + (cnt1 % Mod * cnt2 % Mod) % Mod) % Mod;
            l[val]++;
        }

        return (long long)cnt;
    }
};