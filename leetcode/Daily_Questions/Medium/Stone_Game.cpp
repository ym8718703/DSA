#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>
#include <unordered_map>
using namespace std;

/*
 * LC | 877 | Stone Game
 * Difficulty: medium
 * Topic: Array
 * Date: Aug 5
 * Status: daily | real struggle
 * 
 * 
 * Approach: 
 * Time: O(1) | Space: O(1)
*/

class Solution {
    public:

        bool stoneGame1(vector<int>& piles) {   // Alice will always win
            return true;
        }


        bool stoneGame(vector<int>& piles) {
            int total = 0;
    
            int maximum = 0;
            for(int i = 0; i < piles.size(); i++) {
                total += piles[i];
            }
    
            int st = 0;
            int end = piles.size()-1;
            int alice = 0;
    
            while(st < end) {
                if(piles[st] < piles[end]) {
                    alice += piles[end];
                } else {
                    alice += piles[st];
                }
                st++;
                end--;
                
            }
            return total/2 < alice ? true : false;
        }
    };