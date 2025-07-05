#include<iostream>


using namespace std;


struct ListNode
{
	int val;
	ListNode* next;

	ListNode (int x):val(x),next(nullptr){}
};


ListNode* reversal_list(ListNode* l1) {
	ListNode* pre = nullptr;
	ListNode* cur = l1;

	while (cur != nullptr) {
		ListNode* next = cur->next;
		cur->next = pre;
		pre = cur;
		cur = next;

	}
	return pre;

}

int main() {
	ListNode* l1 = new ListNode(1);
	l1->next = new ListNode(2);
	l1->next->next = new ListNode(3);
	l1->next->next->next = new ListNode(4);
	l1->next->next->next->next = new ListNode(5);

	reversal_list(l1);
}