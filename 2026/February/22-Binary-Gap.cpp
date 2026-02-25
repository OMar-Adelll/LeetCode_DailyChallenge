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
    string binary(int x)
    {
        string rs = "";
        while (x > 0)
        {
            if (x % 2)
                rs += "1";
            else
                rs += "0";
            x /= 2;
        }
        reverse(rs.begin(), rs.end());
        return rs;
    }
    int binaryGap(int x)
    {
        int dist = 0, cur = -1, prv = -1;
        string s = binary(x);
        int n = s.size();
        cout << s << " ";
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '1' && cur == -1 && prv == -1)
            {
                cur = prv = i;
            }
            else if (s[i] == '1' && i > prv)
            {
                dist = max(dist, i - prv);
                cur = prv = i;
            }
        }

        return dist;
    }
};