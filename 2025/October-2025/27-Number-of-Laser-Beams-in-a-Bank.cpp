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
    int numberOfBeams(vector<string> &bank)
    {
        int n = sz(bank);
        int prv = 0, ans = 0;
        for (int i = 0; i < n; i++)
        {
            int ones = count(all(bank[i]), '1');
            ans += (ones * prv);
            prv = ones ? ones : prv;
        }

        return ans;
    }
};