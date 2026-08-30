#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

/*
 * LC | 2091 | Removing Minimum and Maximum From Array
 * Difficulty: medium
 * Topic: Array
 * Date: Aug 30
 * Status: daily | solved
 * 
 * 
 * Approach: simple math and maxmin iterator
 * Time: O(n) | Space: O(1)
*/
class Solution {
    public:
        int minimumDeletions(vector<int>& nums) {
            int n = nums.size();
            auto [min_it, max_it] = minmax_element(nums.begin(), nums.end());
            int i = min_it - nums.begin();
            int j = max_it - nums.begin();
    
            return min({n - abs(i - j) + 1,
                        max(i, j) + 1,
                        n - min(i, j)});
        }
    };