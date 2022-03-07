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
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode * result = new ListNode();
        ListNode * resultTail = result;
        while(list1 != nullptr && list2 != nullptr) {
            if(list1->val < list2->val) {
                resultTail->next = list1;
                resultTail = resultTail->next;
                list1 = list1->next;
            } else {
                resultTail->next = list2;
                resultTail = resultTail->next;
                list2 = list2->next;
            }
        }
        
        while(list1 != nullptr) {
            resultTail->next = list1;
            resultTail = resultTail->next;
            list1 = list1->next;
        }
        
        while(list2 != nullptr) {
            resultTail->next = list2;
            resultTail = resultTail->next;
            list2 = list2->next;
        }
        
        ListNode * temp = result->next;
        delete result;
        return temp;
    }
};
