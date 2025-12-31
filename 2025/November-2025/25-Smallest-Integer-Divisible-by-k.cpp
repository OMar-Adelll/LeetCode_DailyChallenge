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
    int smallestRepunitDivByK(int k)
    {
        if (k % 2 == 0 || k % 5 == 0)
            return -1;
        int dig = 0;
        for (int i = 1; i <= k; i++)
        {
            dig = ((dig * 10 + 1) % k);
            if (dig == 0)
                return i;
        }
        return -1;
    }
};