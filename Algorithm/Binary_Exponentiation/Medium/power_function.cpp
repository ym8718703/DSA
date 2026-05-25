#include <iostream>
using namespace std;

/*
 * LC | 50 | Pow(x,n)  
 * Difficulty: Medium
 * Topic: Math, Recursion
 * Date: 
 * Status: 
 * 
 * 
 * Approach: Modified binary search
 * Time: O() | Space: O()
 */

int main(){
    double x;
    int n;
    cout<<"Enter a number and power: ";
    cin>>x>>n;
    double ans = 1.0;

    if(n < 0){
        x = 1.0/x;
        n = -n;
    }
    
    while(n > 0){
        if(n%2 == 1){
            ans *= x;
        }
        x *= x;
        n /= 2;
    }
    cout<<ans;
}