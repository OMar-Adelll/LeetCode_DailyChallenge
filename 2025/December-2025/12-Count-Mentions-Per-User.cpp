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

#include<ranges>
class Solution {
public:
    vector<int> countMentions(int numberOfUsers, vector<vector<string>>& events) {
        
        ranges::sort(events, {}, [](auto& e) {
            return pair(stoi(e[1]), e[0][2]);
        });

        vector<int> ans(numberOfUsers);
        vector<int> online_t(numberOfUsers);
        for (auto& e : events) {
            int cur_t = stoi(e[1]);
            string& mention = e[2];
            if (e[0][0] == 'O') {
                online_t[stoi(mention)] = cur_t + 60;
            } else if (mention[0] == 'A') {
                for (int& v : ans) {
                    v++;
                }
            } else if (mention[0] == 'H') {
                for (int i = 0; i < numberOfUsers; i++) {
                    if (online_t[i] <= cur_t) { 
                        ans[i]++;
                    }
                }
            } else {
                for (const auto& part : mention | ranges::views::split(' ')) {
                    string s(part.begin() + 2, part.end());
                    ans[stoi(s)]++;
                }
            }
        }
        return ans;
    }
};