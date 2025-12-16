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
    int numberOfWays(string s)
    {
        vector<int> pos;
        for (int i = 0; i < s.size(); i++)
            if (s[i] == 'S')
                pos.push_back(i);
        if (pos.size() == 0 or pos.size() % 2)
            return 0;
        long long pro = 1;
        for (int i = 2; i < pos.size(); i += 2)
        {
            long long cnt = pos[i] - pos[i - 1]; // mora skipped the first pos because the cnt < 2
            pro = (pro * cnt) % Mod;
        }

        return (long long)pro;
    }
};