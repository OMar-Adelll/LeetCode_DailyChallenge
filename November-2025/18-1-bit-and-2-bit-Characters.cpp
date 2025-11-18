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
    bool isOneBitCharacter(vector<int> &bits)
    {
        stack<int> st;
        for (auto &bit : bits)
        {
            if (st.empty())
                st.push(bit);
            else if (st.top() == 1)
                st.pop();
            else if (st.top() == 0 and bit == 1)
                st.pop(), st.push(bit);
        }

        return !st.empty();
    }
};