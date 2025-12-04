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
    int countCollisions(string s)
    {
        int n = s.size(), l = 0, r = n - 1;
        while (l < n && s[l] == 'L')
            l++;
        while (r >= 0 && s[r] == 'R')
            r--;
        int cnt = 0;
        for (int i = l; i <= r; i++)
            if (s[i] == 'L' or s[i] == 'R')
                cnt++;

        return cnt;
    }
};