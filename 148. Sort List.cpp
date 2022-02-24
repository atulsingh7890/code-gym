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
    // merges list head2 into head1.

public:
    ListNode* sortList(ListNode* head) {
        if(head == nullptr || head->next == nullptr)
            return head;
        ListNode *middle_node = splitInMiddle(head);
        
        //sort the two Lists
        ListNode *first_half_sorted = sortList(head);
        ListNode *second_half_sorted = sortList(middle_node);
        //merge two sorted lists
        ListNode * sorted_merged = mergeTwoSortedLists(first_half_sorted, second_half_sorted);
        return sorted_merged;
    }
private:
    ListNode * splitInMiddle(ListNode *head) {
        if(head == nullptr || head->next == nullptr)
            return head;
        ListNode *prev_slow = nullptr;
        ListNode *slow = head;
        ListNode *fast = head;
        while(fast && fast->next) {
            prev_slow = slow;
            slow = slow->next;
            fast = fast->next->next;
        }    
        prev_slow->next = nullptr;    
        return slow;
    }
    ListNode* mergeTwoSortedLists(ListNode* l1, ListNode* l2) {
        ListNode *result = new ListNode(-1);
        ListNode * prev = result;
        while(l1 && l2) {
            if(l1->val < l2->val) {
                prev->next = l1;
                l1 = l1->next;
            } else {
                prev->next = l2;
                l2 = l2->next;
            }
            prev = prev->next;
        }
        prev->next = l1 == nullptr ? l2 : l1;
        return result->next;
    }
    
};
