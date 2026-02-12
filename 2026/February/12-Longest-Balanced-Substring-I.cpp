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
    int longestBalanced(string s)
    {
        int n = s.size(), ans = 0;
        vector<int> f(26, 0);
        for (int i = 0; i < n; i++)
        {
            f.assign(26, 0);
            for (int j = i; j < n; j++)
            {
                f[s[j] - 'a']++;

                int mx = *max_element(f.begin(), f.end());
                int cnt = 0;
                for (int x = 0; x < 26; x++)
                {
                    if (f[x] != 0)
                        cnt++;
                }

                if (mx * cnt == (j - i + 1))
                    ans = max(ans, j - i + 1);
            }
        }

        return ans;
    }
};