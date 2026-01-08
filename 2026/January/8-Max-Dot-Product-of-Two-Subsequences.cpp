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
#define sz(x) x.size()
class Solution
{
public:
    vector<int> a, b;
    vector<vector<ll>> dp;
    ll go(int i, int j)
    {
        if (i >= sz(a) || j >= sz(b))
            return LLONG_MIN / 2;

        ll &ret = dp[i][j];
        if (~ret)
            return ret;

        ll o3 = a[i] * b[j] + max(0LL, go(i + 1, j + 1));
        ll o1 = go(i + 1, j);
        ll o2 = go(i, j + 1);

        return ret = max({o1, o2, o3});
    }
    int maxDotProduct(vector<int> &nums1, vector<int> &nums2)
    {
        this->a = nums1, this->b = nums2;
        dp.assign(sz(nums1) + 1, vector<ll>(sz(nums2) + 1, -1));
        return go(0, 0);
    }
};