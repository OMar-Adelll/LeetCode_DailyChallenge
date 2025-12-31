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
    int maxOperations(string s)
    {
        int n = sz(s);
        int ones = 0, cnt = 0;
        for(int i = 0; i < n;i++)
        {
            if(i > 0 && s[i] == '0' && s[i - 1] != '0') cnt += ones;
            if(s[i] == '1') ones++;
        }

        return cnt;
    }
};