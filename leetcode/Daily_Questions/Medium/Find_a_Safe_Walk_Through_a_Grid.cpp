#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <deque>
using namespace std;

/*
 * LC | 3286 | Find the Safest Walk through the grid
 * Topic: Array
 * Date: July 03
 * Status: daily | struggle is real
 * 
 * 
 * Approach: 
 * Time: O(n) | Space: O(1)
*/


class Solution {
    public:
        bool findSafeWalk(vector<vector<int>>& grid, int health) {
            int m = grid.size();
            int n = grid[0].size();
    
            deque<pair<int, int>> dq;
            vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
    
            dist[0][0] = grid[0][0];
            dq.push_front({0, 0});
    
            int dr[] = {-1, 1, 0, 0};
            int dc[] = {0, 0, -1, 1};
    
            while (!dq.empty()) {
                auto [r, c] = dq.front();
                dq.pop_front();
    
                for (int k = 0; k < 4; k++) {
                    int nr = r + dr[k];
                    int nc = c + dc[k];
    
                    if (nr < 0 || nr >= m || nc < 0 || nc >= n)
                        continue;
    
                    int w = grid[nr][nc];
    
                    if (dist[r][c] + w < dist[nr][nc]) {
                        dist[nr][nc] = dist[r][c] + w;
    
                        if (w == 0)
                            dq.push_front({nr, nc});
                        else
                            dq.push_back({nr, nc});
                    }
                }
            }
    
            int loss = dist[m - 1][n - 1];
            return health - loss >= 1;
        }
    };