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
    int nextBeautifulNumber(int n)
    {
        auto valid = [&](int t) -> bool
        {
            string s = to_string(t);
            vector<int> f(10, 0);
            for (int i = 0; i < sz(s); i++)
            {
                int num = s[i] - '0';
                f[num]++;
            }

            for (auto &c : s)
            {
                int num = c - '0';
                if (num != f[num])
                    return false;
            }

            return true;
        };

        int M = 1e7;
        for (int i = n + 1; i <= M; i++)
        {
            if (valid(i))
                return i;
        }

        return -1;
    }
};