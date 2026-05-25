#include <iostream>
#include <vector>
#include <climits>
using namespace std;

/*
 * LC | 11 | two_pointer With Most Water 
 * Difficulty: Medium
 * Topic: Array, greedy
 * Date: Apr 22
 * Status: SOLVED
 * 
 * 
 * Approach: Two Pointer
 * Time: O() | Space: O(1)
 */

int brute(vector<int> &b){
    int length, height;
    int st = 0;
    int end = b.size();
    int vol = INT_MIN;
    while(st < end){
        for(int i = st+1; i < end; i++){
            length = i - st;
            height = min(b[i], b[st]);
            vol = max(vol, height*length);
        }
        st++;
    }
    return vol;
}

int two_pointer(vector<int> &b){
    int length, height;
    int st = 0;
    int end = b.size();
    int vol = INT_MIN;
    while(st < end){
        length = end - st;
        height = min(b[end], b[st]);
        vol = max(vol,length*height);

        if(b[st] < b[end]){
            st++;
        }else{
            end--;
        }
    }
    return vol;
}

int main(){
    vector<int> arry = {1,8,6,2,5,4,8,3,7};
    int ans = two_pointer(arry);
    cout<<ans;

    return 0 ;
}