#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>
#include <unordered_map>
using namespace std;

/*
 * LC | 1840 |   Maximum Building Height
 * Topic: Array
 * Date: June 21
 * Status: daily | struggling
 * 
 * 
 * Approach: yoga se hoga
 * Time: O() | Space: O()
*/


class Solution {
    public:
        int maxBuilding(int n, vector<vector<int>>& restrictions) {
            restrictions.push_back({1, 0});
            sort(restrictions.begin(), restrictions.end());
    
            int m = restrictions.size();
    
            for (int i = 1; i < m; i++) {
                int dist = restrictions[i][0] - restrictions[i - 1][0];
                restrictions[i][1] = min(restrictions[i][1], restrictions[i - 1][1] + dist);
            }
    
            for (int i = m - 2; i >= 0; i--) {
                int dist = restrictions[i + 1][0] - restrictions[i][0];
                restrictions[i][1] = min(restrictions[i][1], restrictions[i + 1][1] + dist);
            }
    
            int ans = 0;
    
            for (int i = 1; i < m; i++) {
                int x1 = restrictions[i - 1][0];
                int h1 = restrictions[i - 1][1];
                int x2 = restrictions[i][0];
                int h2 = restrictions[i][1];
    
                int dist = x2 - x1;
                int peak = (h1 + h2 + dist) / 2;
                ans = max(ans, peak);
            }
    
            int lastId = restrictions[m - 1][0];
            int lastHeight = restrictions[m - 1][1];
            ans = max(ans, lastHeight + (n - lastId));
    
            return ans;
        }
    };