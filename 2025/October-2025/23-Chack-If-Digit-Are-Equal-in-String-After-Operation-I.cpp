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

class Solution {
public:
    bool hasSameDigits(string s) {
        while (sz(s) > 2) {
            string word = "";
            for (int i = 1; i < sz(s); i++) {
                int x = s[i] - '0', y = s[i - 1] - '0';
                int rs = (x + y) % 10;
                word += to_string(rs);
            }

            s = word;
        }
        return s[0] == s[1];
    }
};