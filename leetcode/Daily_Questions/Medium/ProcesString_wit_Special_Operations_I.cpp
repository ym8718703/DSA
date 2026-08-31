#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>
#include <unordered_map>
using namespace std;

/*
 * LC | 3612 |  Process String with Special Operations I
 * Topic: Array
 * Date: June 16
 * Status: daily | struggling
 * 
 * 
 * Approach: Math
 * Time: O(1) | Space: O(1)
*/


class Solution {
    public:
        string processStr(string s) {
            string result;
        for (char ch : s) {
            if (ch >= 'a' && ch <= 'z') {
                result += ch;                     // Append letter
            }
            else if (ch == '*') {
                if (!result.empty()) {
                    result.pop_back();            // Remove last character
                }
            }
            else if (ch == '#') {
                result += result;                 // Duplicate current result
            }
            else if (ch == '%') {
                reverse(result.begin(), result.end()); // Reverse result
            }
        }
    
        return result;
        }
    };