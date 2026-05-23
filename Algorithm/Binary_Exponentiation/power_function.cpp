#include <iostream>
using namespace std;

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