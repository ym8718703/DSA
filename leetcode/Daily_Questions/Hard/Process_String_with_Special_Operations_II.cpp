#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>
#include <unordered_map>
using namespace std;

/*
 * LC | 3614 |Process String with Special Operations II
 * Topic: Array
 * Date: June 17
 * Status: daily | struggling
 * 
 * 
 * Approach: 
 * Time: O() | Space: O()
*/


class Solution {
    public:
        char processStr(string s, long long k) {
            int n = s.size();
    
            const long long LIMIT = (long long)4e18;
            vector<long long> len(n + 1, 0);
    
            // Forward pass
            for (int i = 0; i < n; i++) {
                char op = s[i];
    
                if ('a' <= op && op <= 'z') {
                    len[i + 1] = min(len[i] + 1, LIMIT);
                }
                else if (op == '*') {
                    len[i + 1] = (len[i] > 0 ? len[i] - 1 : 0);
                }
                else if (op == '#') {
                    len[i + 1] = min(len[i] * 2, LIMIT);
                }
                else { // '%'
                    len[i + 1] = len[i];
                }
            }
    
            if (k >= len[n])
                return '.';
    
            long long pos = k;
    
            // Backward pass
            for (int i = n - 1; i >= 0; i--) {
                char op = s[i];
    
                if ('a' <= op && op <= 'z') {
                    if (pos == len[i])
                        return op;
                }
                else if (op == '*') {
                    // deletion only affects last character,
                    // surviving indices stay unchanged
                }
                else if (op == '#') {
                    if (len[i] > 0)
                        pos %= len[i];
                }
                else if (op == '%') {
                    pos = len[i + 1] - 1 - pos;
                }
            }
    
            return '.';
        }
    };