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
    int countOperations(int num1, int num2)
    {
        if (num1 == num2 && num1 == 0)
            return 0;
        else if (num1 == num2)
            return 1;

        int cnt = 0;
        while (num1 != 0 && num2 != 0)
            (num1 > num2 ? num1 -= num2 : num2 -= num1), cnt++;

        return cnt;
    }
};