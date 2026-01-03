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

#define memo(arr) memset(arr, -1, sizeof(arr))
#define Mod 1000000007
#define ll long long
class Solution
{
public:
    ll dp[5005][4][4][4];
    int go(int rw, int o1, int o2, int o3, int n)
    {
        if (rw == n)
            return 1;

        ll &ret = dp[rw][o1 + 1][o2 + 1][o3 + 1];
        if (~ret)
            return ret;

        ret = 0;
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                for (int k = 0; k < 3; k++)
                    if (i != o1 && j != o2 && k != o3 && i != j && j != k)
                        ret = (ret + go(rw + 1, i, j, k, n)) % Mod;

        return ret;
    }
    int numOfWays(int n)
    {
        memo(dp);
        return go(0, -1, -1, -1, n);
    }
};