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
    string findLexSmallestString(string s, int a, int b)
    {
        int n = sz(s);
        s += s; // this make rotation easliy
        vector<bool> vis(n, false);
        string mini = s;
        for (int i = 0; vis[i] == 0; i = (i + b) % n)
        {
            vis[i] = true;
            for (int j = 0; j <= 9; j++)
            {
                int maxi;
                if (b % 2)
                    maxi = 9;
                else
                    maxi = 0;
                for (int m = 0; m <= maxi; m++)
                {
                    string str = s.substr(i, n);
                    for (int k = 1; k < n; k += 2)
                        str[k] = '0' + (str[k] - '0' + j * a) % 10;
                    for (int k = 0; k < n; k += 2)
                        str[k] = '0' + (str[k] - '0' + m * a) % 10;

                    updmin(mini, str);
                }
            }
        }

        return mini;
    }
};