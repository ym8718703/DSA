#include <iostream>
using namespace std;

void solve(int x) {
    if(x % 2 == 0 && x > 2) cout << "YES";
    else cout << "NO";
}

int main() {
   
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int w;
    cin >> w;
    int t = 1;
    while ( t-- ) {
        solve(w);
    }

    return 0;
}
