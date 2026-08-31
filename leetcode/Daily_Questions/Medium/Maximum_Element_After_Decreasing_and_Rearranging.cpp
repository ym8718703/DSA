#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <deque>
using namespace std;

/*
 * LC | 1846 | Maximum Element After Decreasing and Rearranging
 * Topic: Array
 * Date: June 29
 * Status: daily | struggle is real
 * 
 * 
 * Approach: 
 * Time: O(n) | Space: O(1)
*/


class Solution {
    public:
        int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
            sort(arr.begin(),arr.end());
            arr[0] = 1;
            int ans = 1;
    
            for(int i = 1; i < arr.size(); i++) {
    
                if(arr[i] - arr[i-1] > 1) {
                    arr[i] = arr[i-1]+1;
                }
                ans = max(ans,arr[i]);
            }
            return ans;
        }
    };