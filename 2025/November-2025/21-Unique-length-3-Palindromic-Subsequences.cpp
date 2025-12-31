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
    int countPalindromicSubsequence(string s)
    {
        vector<int> first(26, -1), last(26, -1);
        for (int i = 0; i < s.size(); i++)
        {
            int x = s[i] - 'a';
            if (first[x] == -1)
                first[x] = i;
            last[x] = i;
        }

        int cnt = 0;
        for (int i = 0; i < 26; i++)
        {

            if (first[i] != -1 && last[i] - first[i] > 1)
            {
                int num = 0;
                for (int j = first[i] + 1; j <= last[i] - 1; j++)
                {
                    num |= 1 << (s[j] - 'a');
                }

                cnt += __builtin_popcount(num);
            }
        }

        return cnt;
    }
};