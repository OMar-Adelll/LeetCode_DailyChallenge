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
    int minFlips(string s)
    {
        int n = s.size();
        string s1 = "", s2 = "";
        for (int i = 0; i < 2 * n; i++)
        {
            s1 += ((i & 1) ? '0' : '1');
            s2 += ((i & 1) ? '1' : '0');
        }

        string t = s + s;
        int cnt1 = 0, cnt2 = 0, ans = INT_MAX;
        int l = 0, r = n;

        for (int i = 0; i < s.size(); i++)
        {
            cnt1 += (t[i] != s1[i]);
            cnt2 += (t[i] != s2[i]);
        }
        for (; r < 2 * n; r++, l++)
        {
            cnt1 += (t[r] != s1[r]);
            cnt2 += (t[r] != s2[r]);

            cnt1 -= (t[l] != s1[l]);
            cnt2 -= (t[l] != s2[l]);

            ans = min({ans, cnt1, cnt2});
        }

        return ans;
    }
};