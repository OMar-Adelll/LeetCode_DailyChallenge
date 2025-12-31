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
    vector<string> removeAnagrams(vector<string> &words)
    {
        int n = sz(words);
        stack<string> st;
        st.push(words[0]);
        for (int i = 1; i < n; i++)
        {
            string s1 = st.top(), s2 = words[i];
            sort(all(s1)), sort(all(s2));
            if (s1 != s2)
                st.push(words[i]);
        }

        int x = sz(st);
        vector<string> ans(x);
        for (int i = 0; i < x; i++)
            ans[x - i - 1] = st.top(), st.pop();

        return ans;
    }
};