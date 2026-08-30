#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>
#include <unordered_map>
using namespace std;

/*
 * LC | 3090 | Maximum Length Substring With Two Occurrences
 * Difficulty: easy
 * Topic: Array
 * Date: Aug 15
 * Status: daily | solved
 * 
 * 
 * Approach: hahahaha
 * Time: O(n) | Space: O(1)
*/
class Solution {
public:
    int maximumLengthSubstring(string s) {
        unordered_map<char,int> freq;

        int curr_count = 0;
        int max_count = 0;

        int idx = 0;
        int st = 0;

        while(idx < s.size()) {
            if(freq.find(s[idx]) != freq.end()) {
                if(freq[s[idx]] < 2) {
                    curr_count++;
                    freq[s[idx]] += 1;
                    idx++;
                } else {
                    if(s[st] != s[idx]) {
                        curr_count--;
                        freq[s[st]]--;
                    } else {
                        idx++;
                    }
                    st++;
                }

            } else {
                freq[s[idx]] = 1;
                curr_count++;
                idx++;
            }
            max_count = max(max_count,curr_count);
        }
        return max_count;
    }
};