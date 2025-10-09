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
    long long minTime(vector<int> &skill, vector<int> &mana)
    {
        int n = sz(skill), m = sz(mana);

        vector<ll> row(n + 2);
        for (int i = 0; i < m; i++)
        {
            if (i == 0)
                row[0] = 0;
            else
                row[0] = row[1];

            for (int j = 1; j <= n; j++)
            {
                row[j] = max(row[j + 1], row[j - 1] + mana[i] * skill[j - 1]);
            }

            for (int j = n - 1; j >= 1; j--)
                row[j] = row[j + 1] - (mana[i] * skill[j]);
        }

        return row[n];
    }
};
