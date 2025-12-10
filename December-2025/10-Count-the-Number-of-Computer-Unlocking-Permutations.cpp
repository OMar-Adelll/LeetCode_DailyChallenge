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
    int countPermutations(vector<int> &comp)
    {
        int M = *min_element(comp.begin(), comp.end());
        if (comp[0] != M)
            return 0;
        if (comp.size() > 1 && comp[0] == comp[1])
            return 0;

        int cnt = 0;
        for (int i = 1; i < comp.size(); i++)
            if (comp[i] == comp[0])
                return 0;
            else
                cnt++;

        long long fac = 1;
        for (int i = cnt; i >= 2; i--)
            fac = (fac % Mod * i % Mod) % Mod;
        return (long long)fac;
    }
};