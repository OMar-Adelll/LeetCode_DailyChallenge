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
    int countTrapezoids(vector<vector<int>> &points)
    {
        const int Mod = 1e9 + 7;
        long long cnt = 0, sum = 0;
        map<int, int> m;
        for (auto &v : points)
            m[v[1]]++;
        for (auto &[v, f] : m)
        {
            long long mul = (long long)f * (f - 1) / 2;
            cnt += sum * mul;
            sum += mul;
        }
        return cnt % Mod;
    }
};