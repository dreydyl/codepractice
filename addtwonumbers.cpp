#include <iostream>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

// https://leetcode.com/problems/add-two-numbers/

/*
I: Inputs
- For this problem, we can guarantee that all nodes in l1 and l2 contain only positive integers (0 inclusive) and l1 and l2 are guaranteed to be nodes
- values are _ONLY_ single digits [0-9]
O: Outputs
C: Constraints - time / space complexities
E: Edge cases - 
  - lists are not guaranteed to be the same length
  - 
*/

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    //make first node
    //node current
    //while loop through listnodes
    //add integers
    ListNode* first = new ListNode();
    ListNode* current = first;
    int carry = 0;
    while(l1 != nullptr || l2 != nullptr) {
      ListNode* newNode = new ListNode();
      current->next = newNode;
      int v = 0;
      
      if(l1 == nullptr) {
        v += l2->val;
        l2 = l2->next;
      } else if(l2 == nullptr) {
        v += l1->val;
        l1 = l1->next;
      } else {
        v = l1->val + l2->val;
        l1 = l1->next;
        l2 = l2->next;
      }
      v += carry;
        carry = 0;
        if(v > 9) {
          carry = 1;
          v -= 10;
        }
      newNode->val = v;
      current = current->next;
    }
    if(carry == 1) current->next = new ListNode(carry);
    return first->next;
}

/**
[2, 4, 3]
[5, 6, 4]

[2,4,3,5]
[5,6,4]

[9,9,9,9,9,9,9]
[9,9,9,9,0,0,0]
[8,9,9,9,0,0,0,1]

*/
