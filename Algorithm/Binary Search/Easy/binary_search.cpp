#include <iostream>
#include <vector>
using namespace std;


int linear_search(vector<int> &b, int target){
    for(int i = 0 ; i<b.size() ; i++){
        if(b[i]=target){
            return i;
        }
    }
    return -1;
}


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

    vector<int> b = {1,2,3,6,8};

    cout<<bs(b, 8);

    return 0;

}