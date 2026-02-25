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
    int countBinarySubstrings(string s)
    {
        int n = s.size(), cur = 1, cnt = 0, prv = 0;
        for (int i = 1; i < n; i++)
        {
            if (s[i] == s[i - 1])
            {
                cur++;
            }
            else
            {
                cnt += min(cur, prv);
                prv = cur, cur = 1;
            }
        }

        cnt += min(cur, prv);
        return cnt;
    }
};