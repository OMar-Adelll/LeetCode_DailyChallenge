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
    int totalMoney(int n)
    {
        int st = 1, day = 1, week = 1, sum = 0;
        while (n--)
        {
            sum += st, day++, st++;
            if (day == 8)
                day = 1, st = ++week;
        }

        return sum;
    }
};
