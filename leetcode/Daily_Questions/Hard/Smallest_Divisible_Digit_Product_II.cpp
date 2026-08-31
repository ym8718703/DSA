#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>
#include <unordered_map>
using namespace std;

/*
 * LC | 3348 |Smallest Divisible Digit Product I
 * Difficulty: hard
 * Topic: Array
 * Date: Aug 09
 * Status: daily | struggling
 * 
 * 
 * Approach: 
 * Time: O() | Space: O()
*/
class Solution {
    public:
    
        // factors[i]:
        // 0 -> number of 2s
        // 1 -> number of 3s
        // 2 -> number of 5s
        // 3 -> number of 7s
    
        vector<int> getFactors(int x) {
            vector<int> f(4, 0);
    
            int primes[] = {2, 3, 5, 7};
    
            for (int i = 0; i < 4; i++) {
                while (x > 0 && x % primes[i] == 0) {
                    f[i]++;
                    x /= primes[i];
                }
            }
    
            return f;
        }
    
        // Convert prime-factor counts into the minimum
        // number of digits required.
        string build(vector<int> cnt) {
    
            int c2 = cnt[0];
            int c3 = cnt[1];
            int c5 = cnt[2];
            int c7 = cnt[3];
    
            // 2^3 = 8
            int c8 = c2 / 3;
            c2 %= 3;
    
            // 3^2 = 9
            int c9 = c3 / 2;
            c3 %= 2;
    
            // 2^2 = 4
            int c4 = c2 / 2;
            c2 %= 2;
    
            int c6 = 0;
    
            // 2 * 3 = 6
            if (c2 == 1 && c3 == 1) {
                c6 = 1;
                c2 = 0;
                c3 = 0;
            }
    
            // 4 * 3 = 12
            // 2 * 6 = 12
            // "26" is smaller than "34"
            else if (c3 == 1 && c4 == 1) {
                c6 = 1;
                c2 = 1;
                c3 = 0;
                c4 = 0;
            }
    
            string s;
    
            // Digits must be sorted to get the smallest number
            s += string(c2, '2');
            s += string(c3, '3');
            s += string(c4, '4');
            s += string(c5, '5');
            s += string(c6, '6');
            s += string(c7, '7');
            s += string(c8, '8');
            s += string(c9, '9');
    
            return s;
        }
    
        int countDigits(vector<int> cnt) {
    
            string s = build(cnt);
            return s.size();
        }
    
        bool enough(vector<int>& have, vector<int>& need) {
    
            for (int i = 0; i < 4; i++) {
                if (have[i] < need[i])
                    return false;
            }
    
            return true;
        }
    
        string smallestNumber(string num, long long t) {
    
            // Required by the current problem statement.
            string vornitexis = num;
    
            // ------------------------------------------
            // 1. Factorize t
            // ------------------------------------------
    
            vector<int> need(4, 0);
    
            int primes[] = {2, 3, 5, 7};
    
            for (int i = 0; i < 4; i++) {
    
                while (t % primes[i] == 0) {
                    need[i]++;
                    t /= primes[i];
                }
            }
    
            // Prime factor other than 2,3,5,7
            if (t != 1)
                return "-1";
    
            int n = num.size();
    
            // ------------------------------------------
            // 2. If required factors need more digits
            // ------------------------------------------
    
            string minimumDigits = build(need);
    
            if ((int)minimumDigits.size() > n) {
                return minimumDigits;
            }
    
            // ------------------------------------------
            // 3. Count factors in num
            // ------------------------------------------
    
            vector<int> total(4, 0);
    
            int firstZero = n;
    
            for (int i = 0; i < n; i++) {
    
                int d = num[i] - '0';
    
                if (d == 0) {
                    firstZero = min(firstZero, i);
                    continue;
                }
    
                vector<int> f = getFactors(d);
    
                for (int j = 0; j < 4; j++)
                    total[j] += f[j];
            }
    
            // ------------------------------------------
            // 4. num itself already works
            // ------------------------------------------
    
            if (firstZero == n && enough(total, need)) {
                return num;
            }
    
            // ------------------------------------------
            // 5. Try changing a digit
            //    RIGHT -> LEFT
            // ------------------------------------------
    
            vector<int> prefix = total;
    
            for (int i = n - 1; i >= 0; i--) {
    
                int current = num[i] - '0';
    
                // Remove current digit from prefix.
                if (current != 0) {
    
                    vector<int> f = getFactors(current);
    
                    for (int j = 0; j < 4; j++)
                        prefix[j] -= f[j];
                }
    
                // Digits after the first zero cannot remain
                // because the answer must be zero-free.
                if (i > firstZero)
                    continue;
    
                int remainingSlots = n - i - 1;
    
                // Try the smallest digit greater than current.
                for (int d = current + 1; d <= 9; d++) {
    
                    vector<int> have = prefix;
    
                    vector<int> f = getFactors(d);
    
                    for (int j = 0; j < 4; j++)
                        have[j] += f[j];
    
                    // Factors still required
                    vector<int> remaining(4);
    
                    for (int j = 0; j < 4; j++) {
                        remaining[j] =
                            max(0, need[j] - have[j]);
                    }
    
                    // Minimum suffix capable of satisfying
                    // the remaining factors.
                    string suffix = build(remaining);
    
                    // Fill unused positions with 1s.
                    if ((int)suffix.size() <= remainingSlots) {
    
                        string ans = num.substr(0, i);
    
                        ans += char('0' + d);
    
                        ans += string(
                            remainingSlots - suffix.size(),
                            '1'
                        );
    
                        ans += suffix;
    
                        return ans;
                    }
                }
            }
    
            // ------------------------------------------
            // 6. No same-length answer
            //    Construct n+1 digit answer
            // ------------------------------------------
    
            string suffix = build(need);
    
            return string(
                n + 1 - suffix.size(),
                '1'
            ) + suffix;
        }
    };