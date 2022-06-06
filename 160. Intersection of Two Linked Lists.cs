/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     public int val;
 *     public ListNode next;
 *     public ListNode(int x) { val = x; }
 * }
 */
public class Solution {
    public ListNode GetIntersectionNode(ListNode headA, ListNode headB) {
        HashSet<ListNode> hashSet = new HashSet<ListNode>();
        while(headA != null) {
            hashSet.Add(headA);
            headA = headA.next;
        }
        
        ListNode result = null;
        while(headB != null) {
            if(hashSet.Contains(headB)) {
                result = headB;
                break;
            }
            headB = headB.next;
        }
        
        return result;
    }
}
