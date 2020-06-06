///**
// * Definition for singly-linked list.
// * struct ListNode {
// *     int val;
// *     ListNode *next;
// *     ListNode(int x) : val(x), next(NULL) {}
// * };
// */
//
//#include <iostream>
//#include <vector>
//
//
//
//struct ListNode {
//	int val;
//	ListNode *next;
//	ListNode(int x) : val(x), next(nullptr) {}	
//};
//
//class Solution {
//public:
//	ListNode* middleNode(ListNode* head) {
//		if (!head || !head->next) {
//			return head;
//		}
//
//		ListNode * slow = head;
//		ListNode * fast = head->next;
//
//		while (fast && fast->next != nullptr) {
//			slow = slow->next;
//			fast = fast->next->next;
//		}
//
//		return slow;
//	}
//};
//
//
//int main() {
//
//
//	std::vector<int> num = { 1,2,3,4,5 };
//
//	ListNode *root = nullptr;
//
//	ListNode *temp = root;
//
//	for (int i = 0; i < num.size(); ++i) {
//		if (nullptr == temp) {
//			temp = new ListNode(num[i]);
//			root = temp;
//		}
//		else {
//			temp->next = new ListNode(num[i]);
//			temp = temp->next;
//		}
//	}
//
//	temp = root;
//
//	std::cout << "Original Linked List" << std::endl;
//	while (temp != nullptr) {
//		std::cout << temp->val << "->";
//		temp = temp->next;
//	}	
//
//	std::cout << "nullptr" << std::endl;
//
//	Solution s;
//	temp = s.middleNode(root);
//
//	std::cout << "Original Linked List" << std::endl;
//	while (temp != nullptr) {
//		std::cout << temp->val << "->";
//		temp = temp->next;
//	}
//
//	std::cout << "nullptr" << std::endl;
//
//
//}