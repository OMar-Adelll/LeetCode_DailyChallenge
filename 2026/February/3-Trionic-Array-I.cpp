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
    bool isTrionic(vector<int>& nums) {
        int n = nums.size();
        if(n <= 3) return false;
        int i = 1, cnt1 = 1 , cnt2 = 1, cnt3 = 1;
        while(i < n && nums[i] > nums[i - 1] ) i++, cnt1++;
        while(i < n && nums[i] < nums[i - 1] ) i++,cnt2++;
        while(i < n && nums[i] > nums[i - 1]) i++,cnt3++;

        return (i == n && cnt1 >= 2 && cnt2 >= 2 && cnt3 >= 2);
    }
};