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
    int numSteps(string s)
    {
        s = '0' + s;
        int cnt = 0, n = s.size();
        int ones = count(s.begin(), s.end(), '1');
        while (true)
        {
            if (ones == 1 && s[n - 1] == '1')
                break;

            if (s[n - 1] == '1')
            {
                int idx = n - 1;
                while (s[idx] == '1')
                    s[idx] = '0', idx--;

                s[idx] = '1';
            }
            else
            {
                string ss = s;
                ss[0] = s[n - 1];
                for (int i = n - 1; i >= 1; i--)
                {
                    ss[i] = s[i - 1];
                }

                s = ss;
            }
            cnt++;
            ones = count(s.begin(), s.end(), '1');
        }

        return cnt;
    }
};