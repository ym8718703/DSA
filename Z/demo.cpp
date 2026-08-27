#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int total = 0;

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




    double minPrice(vector<int> & prices,vector<int> &discounts) {
        int d_size = discounts.size();
        int p_size = prices.size();

        double amount = 0.0;
        sort(prices.begin(),prices.end());
        sort(discounts.begin(),discounts.end());


    }
};


int main() {
    int t = 26;
    int x = 1, y = 2, z = 3;
    int ans = x^y;
    cout << ans;
    
    return 0;

}