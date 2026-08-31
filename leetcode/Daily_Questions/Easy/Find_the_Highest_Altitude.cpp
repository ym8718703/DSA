#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>
#include <unordered_map>
using namespace std;

/*
 * LC | 1732 |Find the Highest Altitude
 * Topic: Array
 * Date: June 19
 * Status: daily | solved
 * 
 * 
 * Approach: hahahaha
 * Time: O(n) | Space: O(1)
*/


class Solution {
    public:
        int largestAltitude(vector<int>& gain) {
            int n = gain.size();
            vector<int> alti(n+1,0);
            int ans = 0;
    
            for(int i = 1; i < n+1; i++){
                alti[i] = gain[i-1] + alti[i-1];
                ans = max(ans,alti[i]);
            }
            return ans;
        }
    };