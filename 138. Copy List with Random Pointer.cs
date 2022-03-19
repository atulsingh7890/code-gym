/*
// Definition for a Node.
public class Node {
    public int val;
    public Node next;
    public Node random;
    
    public Node(int _val) {
        val = _val;
        next = null;
        random = null;
    }
}
*/

public class Solution {
    public Node CopyRandomList(Node head) {
        if(head == null) {
            return head;
        }
        
        Node currentNode = head, tempNode = null, newHeader = null, copiedCurrentNode = null;
        
        while(currentNode != null)
        {
            tempNode = new Node(currentNode.val);
            tempNode.next = currentNode.next;
            currentNode.next = tempNode;
            
            currentNode = currentNode.next.next;
        }
        
        currentNode = head;
        
        while(currentNode != null)
        {
            if(currentNode.random != null)
            {
                currentNode.next.random = currentNode.random.next;
            }
            
            currentNode = currentNode.next.next;
        }
        
        newHeader = head.next;
        currentNode = head;
        copiedCurrentNode = newHeader;
        
        while(currentNode != null) 
        {
            currentNode.next = currentNode.next.next;
            currentNode = currentNode.next;
            
            if(copiedCurrentNode.next != null)
            {
                copiedCurrentNode.next = copiedCurrentNode.next.next;
                copiedCurrentNode = copiedCurrentNode.next;
            }
        }
        
        return newHeader;
    }
}
