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

const int Mod = 1000000007;
class Solution
{
public:
    int sum(int x)
    {
        ll up = ((ll)x % Mod * (ll)(x + 1) % Mod) % Mod;
        return up / 2;
    }
    int numSub(string s)
    {
        s += '0';
        int n = s.size(), cnt = 0, ans = 0;
        for (int i = 0; i < n; i++)
        {
            while (i < n && s[i] == '1')
                cnt++, i++;

            int sm = sum(cnt);
            ans = (ans % Mod + sm % Mod) % Mod;
            cnt = 0;
        }
        return ans;
    }
};