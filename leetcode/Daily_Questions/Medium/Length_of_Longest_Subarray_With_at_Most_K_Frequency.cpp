#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>
#include <unordered_map>
using namespace std;

/*
 * LC | 2958 | Length of Longest Subarray With at Most K Frequency
 * Difficulty: medium
 * Topic: Array
 * Date: Aug 13
 * Status: daily | solved
 * 
 * 
 * Approach: 
 * Time: O(n) | Space: O(1)
*/


class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int,int> freq;

        int curr_count = 0;
        int max_count = 0;

        int idx = 0;
        int st = 0;

        while(idx < nums.size()) {
            if(freq.find(nums[idx]) != freq.end()) {
                if(freq[nums[idx]] < k) {
                    curr_count++;
                    freq[nums[idx]] += 1;
                    idx++;
                } else {
                    if(nums[st] != nums[idx]) {
                        curr_count--;
                        freq[nums[st]]--;
                    } else {
                        idx++;
                    }
                    st++;
                }

            } else {
                freq[nums[idx]] = 1;
                curr_count++;
                idx++;
            }
            max_count = max(max_count,curr_count);
        }
        return max_count;
    }
};