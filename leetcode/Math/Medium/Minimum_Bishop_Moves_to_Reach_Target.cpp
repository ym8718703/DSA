#include <iostream>
#include <vector>
using namespace std;

/*
 * LC | 4034 | Minimum Bishop Moves to Reach Target
 * Topic: Math
 * Date: Sep 1
 * Status: SOLVED
 * 
 * 
 * Approach: LOgic
 * Time: O(1) | Space: O(1)
*/

class Solution {
    public:
        int minBishopMoves(vector<int>& source, vector<int>& target) {
            int s0 = source[0], s1 = source[1], t0 = target[0], t1 = target[1];
    
            if ((s0 + s1) % 2 != (t0 + t1) % 2) return -1;
            if ((s0 - s1) == (t0 - t1) || (s0 + s1) == (t0 + t1)) return 1;
            return 2;
        }
    };