#include<iostream>

using namespace std;

struct ListNode
{
	int val;
	ListNode* next;

	ListNode(int x) :val(x), next(nullptr) {};
};



ListNode* reverseList(ListNode* l) {

	ListNode* head = l;
	ListNode* pre = nullptr;

	while (head != nullptr) {
		ListNode* next = head->next;
		head->next = pre;
		pre = head;
		head = next;

	}
	return pre;
}

int main() {
	ListNode* l = new ListNode(1);
	l->next = new ListNode(2);
	l->next->next = new ListNode(3);
	l->next->next->next = new ListNode(4);
	l->next->next->next->next = new ListNode(5);

	ListNode* ans = reverseList(l);
	while (ans != nullptr) {
		cout << ans->val << endl;
		ans = ans->next;
	}
}