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
    int minOperations(string s)
    {
        int cnt1 = 0, cnt2 = 0;
        string s1 = s, s2 = s;
        // zeros are even & ones are odd
        for (int i = 0; i < s.size(); i++)
        {
            if (i & 1)
            {
                if (s1[i] != '1')
                    cnt1++, s1[i] = '1';
            }
            else
            {
                if (s1[i] != '0')
                    cnt1++, s1[i] = '0';
            }
        }

        // zeros are odd and ones is even
        for (int i = 0; i < s.size(); i++)
        {
            if (i & 1)
            {
                if (s2[i] != '0')
                    s2[i] = '0', cnt2++;
            }
            else
            {
                if (s2[i] != '1')
                    s2[i] = '1', cnt2++;
            }
        }

        return min(cnt1, cnt2);
    }
};