//
//  AddTwoNumbers.cpp
//  Algorithm
//
//  Created by YooBin Jo on 2020/08/12.
//  Copyright © 2020 YooBin Jo. All rights reserved.
//

#include <stdio.h>
#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int sum = 0;
        ListNode *answer = NULL;
        ListNode ** node = &answer;
        while(l1 != NULL || l2 != NULL || sum > 0) {
            if(l1 != NULL) {
                sum += l1->val;
                l1 = l1->next;
            }
            if(l2 != NULL) {
                sum += l2->val;
                l2 = l2->next;
            }
            
            (*node) = new ListNode(sum % 10);
            sum /= 10;
            node = &((*node)->next);
        }
        
        
        return answer;
    }
};
int main(void) {
    int a[3] = {2, 4, 3};
    int b[3] = {5, 6, 4};
    ListNode l1, l2;
    
    
    return 0;
}
