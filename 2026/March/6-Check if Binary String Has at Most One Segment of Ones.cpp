// بسم الله الرحمن الرحيم
//  وَأَنْ لَيْسَ لِلْإِنسَانِ إِلَّا مَا سَعَىٰ
//  Free Palestine
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define i(x) (x - 'a')
#define nl '\n'
#define sz(x) (int)(x).size()
#define updmax(a, x) (a = max((a), (x)))
#define updmin(a, x) (a = min((a), (x)))
#define all(vec) (vec).begin(), (vec).end()
class Solution
{
public:
    bool checkOnesSegment(string s)
    {
        s += '0';

        int cnt = count(s.begin(), s.end(), '1');
        int mx = 0, curr = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '1')
                curr++;
            else
                mx = max(mx, curr), curr = 0;
        }

        return cnt == mx;
    }
};