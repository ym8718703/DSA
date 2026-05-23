#include <iostream>
#include <vector>
using namespace std;

//time complexity = O(n)
//SC = O(1)
vector<int> product(vector<int> &nums) {
    int n = nums.size();
    vector<int> ans(n , 1);

    for(int i = 1; i < n; i++) {
        ans[i] = ans[i-1]*nums[i-1];
    }
    int suffix = 1;
    for(int i = n-2; i >= 0; i--){
        suffix *= nums[i+1];
        ans[i] = ans[i]*suffix;
    }
    return ans;
}

int main() {
    vector<int> array = {1,2,3,4,5,6};
    for(int val : product(array)) {
        cout<<val<<" ";
    }
    return 0;
    
}