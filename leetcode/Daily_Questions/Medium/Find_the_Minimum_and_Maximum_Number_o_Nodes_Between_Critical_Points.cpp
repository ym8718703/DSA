#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>
#include <unordered_map>
using namespace std;

/*
 * LC | 2058 |  Find the Minimum and Maximum Number of Nodes Between Critical Points
 * Topic: Linked List
 * Date: Aug 31
 * Status: daily | solved
 * 
 * 
 * Approach: Math
 * Time: O(N+M) | Space: O(M)
*/



struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
    public:
        vector<int> nodesBetweenCriticalPoints(ListNode* head) {
            
           vector<int> points;
           ListNode* before = head;
           head = head -> next;
           ListNode* after = head -> next;
           int idx = 2;
           
           if(after == NULL) return {-1,-1};
           
           while(after != NULL) {
               
               if(head -> val > before -> val && head -> val > after -> val) {
                   points.push_back(idx);
               } else if(head -> val < before -> val && head -> val < after -> val) {
                   points.push_back(idx);
               }
               idx++;
               before = head;
               head = after;
               after = after -> next;
           }
           int n = points.size();
           
           if(n == 1 || n == 0) return {-1,-1};
           int maxdistance = points[n-1] - points[0];
           int mindistance = INT_MAX;
           for(int i = 0; i < n-1; i++) {
               mindistance= min(mindistance,points[i+1]-points[i]);
           }
           
           return {mindistance, maxdistance};
            }
        };