#include <iostream>
#include <climits>
using namespace std;


class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {


        for(int i = 0; i < s.size()-2; i++) {
            int mid = i + 1;
            int end = i + 2;

            if(s[i] == '0' && s[mid] == '1' && s[end] == '0') {
                s[mid] = '0';
            } else if(s[i] == '1' && s[mid] == '0' && s[end] == '1') {
                s[mid] = '1';
            }

        }
        int ans = INT_MIN;
        int count = 0;
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '0') {
                count++;
                ans = max(ans,count);
            } else {
                count = 1;
            }
        }
        return ans;
    }
};
int main() {
    string s = "0100";
    Solution S1;
    for(int i = 0; i < s.size()-2; i++) {
        int mid = i + 1;
        int end = i + 2;

        if(s[i] == '0' && s[mid] == '1' && s[end] == '0') {
            s[mid] = '0';
        } else if(s[i] == '1' && s[mid] == '0' && s[end] == '1') {
            s[mid] = '1';
        }

    }

    cout << s;
}