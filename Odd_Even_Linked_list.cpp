//
//struct ListNode {
//     int val;
//     ListNode *next;
//     ListNode() : val(0), next(nullptr) {}
//     ListNode(int x) : val(x), next(nullptr) {}
//     ListNode(int x, ListNode *next) : val(x), next(next) {}
//};
// 
//class Solution {
//public:
//	ListNode* oddEvenList(ListNode* head) {
//		
//		if (head == nullptr) {
//			return head;
//		}
//
//		ListNode *current_node = head;
//
//		ListNode *odd_head_start = nullptr, *odd_head_end = nullptr;
//		ListNode *even_head_start = nullptr, *even_head_end = nullptr;
//
//		while (current_node && current_node->next) {
//			ListNode *next_even_node = current_node->next;		
//
//			odd_head_start  ? odd_head_end->next = current_node : odd_head_start = current_node ;
//
//			even_head_start ? even_head_end->next = next_even_node : even_head_start = next_even_node;
//
//			odd_head_end = current_node;			
//			even_head_end = next_even_node;
//
//			current_node = current_node->next->next;
//
//			odd_head_end->next = nullptr;
//			even_head_end->next = nullptr;
//
//		}
//
//		//See if we are left with one odd node
//		if (current_node) {
//			odd_head_start ? odd_head_end->next = current_node : odd_head_start = current_node;
//			odd_head_end = current_node;
//		}
//
//		//Sticth Toegether Odd and Even Nodes
//		odd_head_end->next = even_head_start;
//
//		return odd_head_start;
//	}
//};
//
//
//
//int main() {
//	{
//		ListNode *root = new ListNode(1);
//		ListNode *temp = root;
//		for (int i = 2; i <= 5; ++i) {
//			temp->next = new ListNode(i);
//			temp = temp->next;
//		}
//
//		Solution s;
//		s.oddEvenList(root);
//	}
//}