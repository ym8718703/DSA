#include <iostream>
#include <vector>
using namespace std;

int function(vector<int> a, int sz){
    a.push_back(99);
}

int main(){
    vector<int> vec = {1,2,3,4,5};
    function(vec,5);
    for(int val : vec){
        cout<<val<<" ";
    }    
    return 0;
}