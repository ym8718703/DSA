#include <iostream>
#include <vector>
using namespace std;


/*
 * LC | 703 } | Binay Search
 * Difficulty: Easy
 * Topic: BS
 * Date: Apr 5
 * Status: SOLVED
 * 
 * 
 * Approach: binary search
 * Time: O(log n) | Space: O(1)
 */
int linearsearch(int a[], int target){
    int n = sizeof(a)/4;
    for(int i = 0 ; i < n ; i++){
        if(target = a[i]){
            return i;
        }
    }
    return -1;
}

int bs(vector<int>& b, int target){
    int st=0; int end = b.size(), mid;
    

    while(st <= end){
        mid = st + (end-st)/2; // mid = (st + end)/2
        if(target > b[mid]){
            st = mid+1;
        }
        else if(target < b[mid]){
            end = mid-1;
        }
        else{
            return mid;
        }
    }
    return -1;
}
int main(){
    vector<int> a = {1,2,3,7,9,12,14,38};
    int z = 14;

    vector<int> b = {1,2,3,6,8};
    int x = 8;
    int y = 10;

    cout<<bs(b, x);

    return 0;

}