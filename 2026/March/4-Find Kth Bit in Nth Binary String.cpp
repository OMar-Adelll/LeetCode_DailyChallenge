// بسم الله الرحمن الرحيم
//  وَأَنْ لَيْسَ لِلْإِنسَانِ إِلَّا مَا سَعَىٰ
//  Free Palestine
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define i(x) (x - 'a')
#define nl '\n'
#define sz(x) (int)(x).size()
#define updmax(a, x) (a = max((a), (x)))
#define updmin(a, x) (a = min((a), (x)))
#define all(vec) (vec).begin(), (vec).end()

class Solution
{
public:
    char go(int n, int k)
    {
        if (n == 1)
            return '0';

        int sublen = (1 << n) - 1, mid = sublen / 2 + 1;
        if (k == mid)
            return '1';

        if (k < mid)
            return go(n - 1, k);

        return (go(n - 1, sublen - k + 1) == '0' ? '1' : '0');
    }

    char findKthBit(int n, int k)
    {
        return go(n, k);
    }
};