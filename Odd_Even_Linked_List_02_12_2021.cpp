//https://leetcode.com/problems/odd-even-linked-list/
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
    ListNode* oddEvenList(ListNode* head) {
        if(head == nullptr || head->next == nullptr)
            return head;
        
        ListNode * oddlist_head = new ListNode();
        ListNode * oddlist_current = oddlist_head;
        ListNode * even_list_head = new ListNode();
        ListNode * evenList_current = even_list_head;
        
        ListNode * current = head;
        int number = 0;
        while(current) {
            
            if(number == 0 ) {
                // put this node behind odd list
                oddlist_current->next = current;
                oddlist_current = current;
                
            } else {
                // put this node behind even list
                evenList_current->next = current;
                evenList_current = current;
            }
            
            current = current->next;
            number = 1 - number;
        }
        
        
        oddlist_current->next = even_list_head->next;
        evenList_current->next = nullptr;

        ListNode * result = oddlist_head->next;

        delete oddlist_head;
        delete even_list_head;
        
        return result;
        
    }
};
