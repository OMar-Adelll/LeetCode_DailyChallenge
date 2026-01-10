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

#define sz(x) x.size()
#define cov(x) (int)x
class Solution
{
public:
    string s, t;
    vector<vector<int>> dp;
    int go(int i, int j)
    {
        if (i >= sz(s) && j >= sz(t))
            return 0;

        if (i >= sz(s))
            return cov(t[j]) + go(i, j + 1);
        if (j >= sz(t))
            return cov(s[i]) + go(i + 1, j);

        int &ret = dp[i][j];
        if (~ret)
            return ret;

        if (s[i] == t[j])
            return ret = go(i + 1, j + 1);

        int o1 = cov(s[i]) + go(i + 1, j);
        int o2 = cov(t[j]) + go(i, j + 1);

        return ret = min(o1, o2);
    }
    int minimumDeleteSum(string s1, string s2)
    {
        s = s1, t = s2;
        dp.assign(sz(s1) + 1, vector<int>(sz(s2) + 1, -1));
        return go(0, 0);
    }
};