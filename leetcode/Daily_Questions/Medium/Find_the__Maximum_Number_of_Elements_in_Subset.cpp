#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <deque>
using namespace std;

/*
 * LC | 3020 | Find the Maximum Number of Elements in Subset
 * Topic: Array
 * Date: June 27
 * Status: daily | struggle is real
 * 
 * 
 * Approach: 
 * Time: O(n) | Space: O(1)
*/


class Solution {
    public:
        int maximumLength(vector<int>& nums) {
            unordered_map<long long, int> freq;
            for (int x : nums) freq[x]++;
    
            int ans = 1;
    
            // Special case: 1 -> 1^2 -> 1, so we need the largest odd count.
            if (freq.count(1)) {
                ans = max(ans, freq[1] % 2 == 1 ? freq[1] : freq[1] - 1);
            }
    
            for (auto &[num, count] : freq) {
                if (num == 1) continue;
    
                long long cur = num;
                int len = 0;
    
                while (freq[cur] >= 2) {
                    len += 2;
                    cur = cur * cur;
    
                    if (!freq.count(cur)) {
                        len--; // previous value becomes the middle element
                        break;
                    }
                }
    
                if (freq.count(cur)) {
                    len++; // current value can be the middle element
                }
    
                ans = max(ans, len);
            }
    
            return ans;
        }
    };