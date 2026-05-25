#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
 * LC | 169 | Majority Element
 * Difficulty: Easy
 * Topic: Array
 * Date: Apr 21
 * Status: SOLVED
 * 
 * 
 * Approach: Brute force
 * Time: O(n2) | Space: O(1)
 */

int brute_force(vector<int> vec){ //O(n^2)
    for(int i = 0 ; i < vec.size() ; i++){
        int frequency = 1;
        for(int j = i+1 ; j < vec.size() ; j++){
            if(vec[i] == vec[j]){
                frequency++;
            }
        }
        if(frequency > vec.size()/2){
            return vec[i];
        }
    }
    return -1;
}
/*
* Approach: My Optimised
* Time: O(n) | Space: O(1)
*/

int optimised(vector<int> array){
    sort(array.begin(), array.end());

    int ans = array[0];
    int frequency = 1;
    int n = array.size();
    for(int i = 1 ; i < n ; i++){
        if(array[i] == array[i-1]){
            frequency++;
        }else{
            frequency = 1;
            ans = array[i];
        }
        if(frequency > n/2){
            return ans;
        }
    }
    return ans;
}

/*
* Approach: Apna College
* Time: O(n) | Space: O(1)
*/

int maxelement(vector<int> &vec) {
    int fre = 0, ans = 0;
    for (int i = 0; i < vec.size(); i++) {
        if (fre == 0) {       
            ans = vec[i];
        }
        if (ans == vec[i]) {  
            fre++;
        } else {
            fre--;
        }
    }
    return ans;
}

int main(){
    vector<int> array = {3,1,3,2,3,2,3,1,3,1};
    cout<<maxelement(array);
    return 0 ;
}