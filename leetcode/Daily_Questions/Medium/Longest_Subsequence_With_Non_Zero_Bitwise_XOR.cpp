#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>
using namespace std;

/*
 * LC | 3702 | Longest Subsequence With Non-Zero Bitwise XOR
 * Difficulty: medium
 * Topic: Array
 * Date: Aug 15
 * Status: daily | solved
 * 
 * 
 * Approach: 
 * Time: O(n) | Space: O(1)
*/

class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n = nums.size();

        if(n == 1 && nums[0] != 0) return 1;
        int count = 1;
        int zero = 0;
        if(nums[0] == 0) zero++;
        int current= nums[0];

        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] == 0) zero++;
            current = nums[i]^current;
        }

        if(zero == n) return 0;
        if(current == 0) return n-1;
        else return n;
        return 0;
    }
};


