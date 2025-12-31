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
    int bestClosingTime(string customers)
    {
        int best = 0, prefix = 0, bestTime = 0;
        for (int i = 0; i < customers.size(); i++)
        {
            prefix += customers[i] == 'Y' ? 1 : -1;

            if (prefix > best)
            {
                best = prefix;
                bestTime = i + 1;
            }
        }

        return bestTime;
    }
};