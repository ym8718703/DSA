#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

/*
 * LC | 3614 | Process String with Special Operations II
 * Difficulty: Hard
 * Topic: String
 * Date: June 17
 * Status: daily
 * 
 * 
 * Approach : 
 * Time: O(n) | Space: O(n)
 */


 class Solution {
    public:
        char processStr(string s, long long k) {
            int n = s.size();
            vector<long long> len(n + 1, 0);
    
            
            for (int i = 0; i < n; i++) {
                len[i + 1] = len[i];
    
                if (s[i] >= 'a' && s[i] <= 'z') {
                    len[i + 1]++;
                }
                else if (s[i] == '*') {
                    if (len[i + 1] > 0)
                        len[i + 1]--;
                }
                else if (s[i] == '#') {
                    len[i + 1] = min(len[i] * 2, k + 1);
                }
                // '%' -> length unchanged
    
                len[i + 1] = min(len[i + 1], k + 1);
            }
    
            if (k >= len[n])
                return '.';
    
            long long pos = k;
    
            for (int i = n - 1; i >= 0; i--) {
                char op = s[i];
    
                if (op >= 'a' && op <= 'z') {
                    if (pos == len[i])
                        return op;
                }
                else if (op == '*') {
                    if (len[i] > len[i + 1])
                        pos = len[i] - 1;
                }
                else if (op == '#') {
                    if (len[i] > 0)
                        pos %= len[i];
                }
                else if (op == '%') {
                    pos = len[i] - 1 - pos;
                }
            }
    
            return '.';
        }
    };
};


int main(){
    Solution S1;
    string n = "ad%fb#fn*";
    cout<< S1.processStr(n,2);
    return 0;
}