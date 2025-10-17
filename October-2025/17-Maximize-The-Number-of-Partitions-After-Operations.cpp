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
    int CntBits(int x)
    {
        return __builtin_popcount(x);
    }
    string FixSize(string s)
    {
        s = s + '#';
        s = '#' + s;
        return s;
    }
    int maxPartitionsAfterOperations(string s, int k)
    {
        int n = sz(s);
        if (k >= 26)
            return 1;

        s = FixSize(s);
        vector<int> prefix(n + 2, 0), pvls(n + 2, 0);
        int pre = 0, pv = 0;
        for (int i = 1; i <= n; i++)
        {
            int bit = (1 << (s[i] - 'a'));
            pv |= bit;
            if (CntBits(pv) > k)
                pre++, pv = bit;

            prefix[i] = pre;
            pvls[i] = pv;
        }

        vector<int> suffix(n + 2, 0), svls(n + 2, 0);
        int suff = 0, sv = 0;
        for (int i = n; i >= 1; i--)
        {
            int bit = (1 << (s[i] - 'a'));
            sv |= bit;
            if (CntBits(sv) > k)
                suff++, sv = bit;

            suffix[i] = suff;
            svls[i] = sv;
        }

        int maxi = 0;
        for (int i = 1; i <= n; i++)
        {
            int val = prefix[i - 1] + suffix[i + 1];
            int pvl = pvls[i - 1];
            int svl = svls[i + 1];

            int x = pvl | svl;

            if (CntBits(x) <= k - 1)
                val++;
            else if (CntBits(pvl) == k && CntBits(svl) == k && CntBits(x) < 26)
                val += 3;
            else
                val += 2;

            updmax(maxi, val);
        }

        return maxi;
    }
};