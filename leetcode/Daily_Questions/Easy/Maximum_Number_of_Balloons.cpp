#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>
using namespace std;

/*
 * LC | 1189 | Maximum Number of Balloons
 * Topic: Array
 * Date: June 22
 * Status: daily | solved
 * 
 * 
 * Approach: hahahaha
 * Time: O(n) | Space: O(1)
*/

class Solution {
    public:
        int maxNumberOfBalloons(string text) {
            int b=0, a=0, l=0, o=0, n=0;
            int count;
            
            for(char letter : text){
                if(letter == 'b') ++b;
                else if(letter == 'a') ++a;
                else if(letter == 'l') ++l;
                else if(letter == 'o') ++o; 
                else if(letter == 'n') ++n;
            }
            count = min(b,min(a,min(l/2,min(o/2,n))));
            
            return count;
        }
    };