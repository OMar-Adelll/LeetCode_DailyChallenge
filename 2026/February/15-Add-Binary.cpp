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
    string addBinary(string a, string b)
    {
        int n = max(a.size(), b.size());
        while (n > a.size())
            a = '0' + a;
        while (n > b.size())
            b = '0' + b;

        string res = "";
        bool carry = false;
        for (int i = n - 1; i >= 0; i--)
        {
            if (a[i] == '1' && b[i] == '1')
                res += (carry ? '1' : '0'), carry = true;
            else if (a[i] == '0' && b[i] == '0')
                res += (carry ? '1' : '0'), carry = false;
            else
                res += (carry ? '0' : '1');
        }

        if (carry)
            res += '1';
        reverse(res.begin(), res.end());
        return res;
    }
};