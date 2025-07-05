#include<iostream>
#include<vector>

using namespace std;


struct ListNode {
	int val;
	ListNode* next;

	ListNode(int x) :val(x), next(nullptr) {}
};

ListNode* extract_duplicates(ListNode* l1, ListNode* l2) {
	ListNode dummy =  ListNode(0);
	ListNode* result = &dummy;
	ListNode* p1 = l1;  // 指向第一个链表的当前节点
	ListNode* p2 = l2;  // 指向第二个链表的当前节点

	//当其中一个为nullptr时会退出执行，故需对长的链表继续排序去重
	while (p1 !=nullptr && p2 !=nullptr)
	{
		if (p1 ->next !=nullptr &&(p1->next->val == p1->val))
			p1 = p1->next;
		if (p2->next!=nullptr &&(p2->next->val == p2->val))
			p2 = p2->next;
		if (p1->val != p2->val)
		{
			if (p1->val < p2->val)
			{
				//if(p1->next!=nullptr)
				{
					result->next = p1;
					result = p1;
					p1 = p1->next;
					
				}
			}
			else {
				//if(p2->next!=nullptr)
				{
					result->next = p2;
					result = p2;

					p2 = p2->next;
				}
			}

		}
		else {
			p1 = p1->next;
		}
	}
	while (p1 !=nullptr)
	{
		if (p1->val != result->val) {
			result->next = p1;
			result = p1;
			p1 = p1->next;
		}
		else
			p1 = p1->next;

	}
	while (p2 != nullptr)
	{
		if (p2->val != result->val) {
			result->next = p2;
			result = p2;
			p2 = p2->next;
		}
		else
			p2 = p2->next;

	}
	result->next = nullptr;
	return dummy.next;

}
void printList(ListNode* head) {
	while (head != nullptr) {
		std::cout << head->val << " ";
		head = head->next;
	}
	std::cout << std::endl;
}

void func_my() {
	ListNode* l1 = new ListNode(1);
	l1->next = new ListNode(2);
	l1->next->next = new ListNode(3);
	l1->next->next->next = new ListNode(4);

	ListNode* l2 = new ListNode(1);
	l2->next = new ListNode(3);
	l2->next->next = new ListNode(3);

	ListNode* result = extract_duplicates(l1, l2);

	printList(result);
}




int main() {

	func_my();

	//func_other();

}