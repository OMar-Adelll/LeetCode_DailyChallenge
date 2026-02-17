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

#define PopCnt(x) __builtin_popcount(x)
#define sz(x) (int)x.size()
class Solution
{
public:
    vector<string> readBinaryWatch(int turnedOn)
    {
        vector<string> ans;
        for (int h = 0; h <= 11; h++)
        {
            for (int m = 0; m <= 59; m++)
            {
                if (PopCnt(h) + PopCnt(m) == turnedOn)
                {
                    string hours = to_string(h);
                    string minutes = to_string(m);
                    if (sz(minutes) == 1)
                        minutes = "0" + minutes;

                    ans.push_back(hours + ":" + minutes);
                }
            }
        }

        return ans;
    }
};