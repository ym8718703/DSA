#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

class Solution {
    public:
        string smallestNumber(string num, long long t) {
            long long temp = t;
            while(temp != 1) {
                if(temp % 2 == 0) temp /= 2;
                else if(temp % 3 == 0) temp /= 3;
                else if(temp % 5 == 0) temp /= 5;
                else if(temp % 7 == 0) temp /= 7;
                else return "-1";
            }
    
            string ans;
            int temp_no;
            int n = 0;
            int product = 1;
    
            for(int i = 0; i < (int)num.size(); i++) {
                n = n*10 + (num[i] - '0');
            }
            while(product % t != 0 && product != 0) {
                ans = to_string(n);
                while(n > 0) {
                    product *= n%10;
                    n /= 10;
                }
                n++;
            }
            return ans;
        }
    }; 


int main() {

    long long t = 256;
    string num = "1234";

    Solution S1;
    cout << S1.smallestNumber(num,t);
    return 0;

}