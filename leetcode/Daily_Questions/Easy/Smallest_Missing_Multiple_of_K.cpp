#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>
using namespace std;

/*
 * LC | 3718 | Smallest Missing Multiple of K
 * Difficulty: easy
 * Topic: Array
 * Date: Aug 25
 * Status: daily | solved
 * 
 * 
 * Approach: unordered_set
 * Time: O(n*m) | Space: O(m)
*/


class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int> seen(nums.begin(), nums.end());
        int ans = k;
        while (seen.count(ans)) {
            ans += k;
        }
        return ans;
    }
};

class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int> mp;
        
        for(int val : nums) {
            if(val % k == 0) {
                mp.insert(val);
            }
        }

        int num = k;
        while(true) {
            if(mp.find(num) == mp.end()) {
                return num;
            }
            num += k;
        }

    }
};

