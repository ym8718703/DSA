#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <deque>
using namespace std;

/*
 * LC | 1358 |Number of Substrings Containing All Three Characters
 * Topic: Array
 * Date: July 01
 * Status: daily | solved
 * 
 * 
 * Approach: 
 * Time: O(n) | Space: O(1)
*/


class Solution {
    public:
        int numberOfSubstrings(string s) {
            int lastA = -1, lastB = -1, lastC = -1;
            int ans = 0;
    
            for (int i = 0; i < s.size(); i++) {
                if (s[i] == 'a') lastA = i;
                else if (s[i] == 'b') lastB = i;
                else lastC = i;
    
                int mn = min({lastA, lastB, lastC});
                if (mn != -1)
                    ans += mn + 1;
            }
    
            return ans;
        }
    };