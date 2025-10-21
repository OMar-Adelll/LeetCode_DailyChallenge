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
#define f first
#define s second

class Solution
{
public:
    int maxFrequency(vector<int> &nums, int k, int ope)
    {
        sort(all(nums));
        map<ll, int> m;
        set<ll> uni;
        for (auto &c : nums)
            m[c]++, uni.insert(c + k), uni.insert(c - k), uni.insert(c);

        vector<ll> numbers(all(uni));
        ll rs = 1;
        for (auto &c : numbers)
        {
            ll mnval = c - k;
            ll mxval = c + k;
            
            int l = lower_bound(all(nums), mnval) - nums.begin();
            int r = upper_bound(all(nums), mxval) - nums.begin();

            if (r - l > 0)
            {
                ll mx_op = r - l - m[c];
                ll mx_fr = min(mx_op, (ll)ope) + m[c];
                updmax(rs, mx_fr);
            }
        }

        return rs;
    }
};