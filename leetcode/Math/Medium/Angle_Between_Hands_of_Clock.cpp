#include <iostream>
#include <vector>
using namespace std;

/*
 * LC | 1344 |  Angle Between Hands of a Clock
 * Difficulty: Medium
 * Topic: Math
 * Date: June 18
 * Status: SOLVED
 * 
 * 
 * Approach: 
 * Time: O(1) | Space: O(1)
*/

class Solution {
    public:
        double angleClock(int hour, int minutes) {
            double minangle = 6*minutes;
            double hourangle = 30*(hour%12) + minutes/2.0;
            double angle = fabs(hourangle - minangle);
            return min(angle,360-angle);
        }
    };