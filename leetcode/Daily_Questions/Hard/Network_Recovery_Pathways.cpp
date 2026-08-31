#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>
#include <unordered_map>
using namespace std;

/*
 * LC | 3348 |Smallest Divisible Digit Product I
 * Topic: Array
 * Date: July 03
 * Status: daily | struggling
 * 
 * 
 * Approach: 
 * Time: O() | Space: O()
*/


class Solution {
    public:
        int findMaxPathScore(vector<vector<int>>& edges,
                         vector<bool>& online,
                         long long k) {
            int n = online.size();
    
            vector<vector<pair<int, int>>> g(n);
            vector<int> indeg(n);
    
            int mx = 0;
            for (auto &e : edges) {
                int u = e[0], v = e[1], c = e[2];
                g[u].push_back({v, c});
                indeg[v]++;
                mx = max(mx, c);
            }
    
            vector<int> topo;
            queue<int> q;
            for (int i = 0; i < n; i++) {
                if (indeg[i] == 0) q.push(i);
            }
    
            while (!q.empty()) {
                int u = q.front();
                q.pop();
                topo.push_back(u);
    
                for (auto &[v, c] : g[u]) {
                    if (--indeg[v] == 0)
                        q.push(v);
                }
            }
    
            auto can = [&](int x) {
                const long long INF = 4e18;
                vector<long long> dp(n, INF);
                dp[0] = 0;
    
                for (int u : topo) {
                    if (dp[u] == INF) continue;
    
                    for (auto &[v, c] : g[u]) {
                        if (c < x) continue;
                        if (v != n - 1 && !online[v]) continue;
    
                        dp[v] = min(dp[v], dp[u] + c);
                    }
                }
    
                return dp[n - 1] <= k;
            };
    
            int lo = 0, hi = mx, ans = -1;
    
            while (lo <= hi) {
                int mid = lo + (hi - lo) / 2;
    
                if (can(mid)) {
                    ans = mid;
                    lo = mid + 1;
                } else {
                    hi = mid - 1;
                }
            }
    
            return ans;
        }
    };