#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>
using namespace std;

/*
 * LC | 1967 | Number of Strings That Appear as Substrings in Word
 * Topic: Array
 * Date: June 29
 * Status: daily | solved
 * 
 * 
 * Approach: hahahaha
 * Time: O(n) | Space: O(1)
*/

class Solution {
    public:
        int numOfStrings(vector<string>& patterns, string word) {
            int count = 0;
    
            for (string &p : patterns) {
                if (word.find(p) != string::npos) {
                    count++;
                }
            }
    
            return count;
        }
    };