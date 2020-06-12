#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *result, *p;
        result = new ListNode(0);
        p = result;

        int c = 0;
        while(l1 != NULL && l2 != NULL){
            c = l1->val + l2->val + c;
            p->next = new ListNode(c % 10);
            p = p->next;
            c = c / 10;
            l1 = l1->next;
            l2 = l2->next;
        }

        while(l1 != NULL){
            c = l1->val + c;
            p->next = new ListNode(c % 10);
            p = p->next;
            c = c / 10;
            l1 = l1->next;
        }
        
        while(l2 != NULL){
            c = l2->val + c;
            p->next = new ListNode(c % 10);
            p = p->next;
            c = c / 10;
            l2 = l2->next;
        }

        if(c != 0){
            p->next = new ListNode(c % 10);
            p = p->next;
        }
        
        p = result->next;
        delete result;
        return p;
    }
};
