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
    int maxBottlesDrunk(int num, int ex)
    {
        ll cnt = num;
        ll em = num;
        num = 0;
        while (true)
        {
            if (em + num < ex)
                break;

            em += num, num = 0;
            while (em >= ex)
                num++, em -= ex, cnt++, ex++;
        }
        return cnt;
    }
};
