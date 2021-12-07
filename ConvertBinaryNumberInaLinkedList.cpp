//https://leetcode.com/problems/convert-binary-number-in-a-linked-list-to-integer/
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
    int getDecimalValue(ListNode* head) {
        return getDecimalValueHelper(head).first;
    }
private:
    std::pair<int,int> getDecimalValueHelper(ListNode *head) {
        if(head->next == nullptr)
            return {head->val,1};
        
        auto [result,previousMultiplier] = getDecimalValueHelper(head->next);
        
        
        return {result + (( head->val )<<previousMultiplier), previousMultiplier + 1};
    }
};
