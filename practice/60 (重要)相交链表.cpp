#include<iostream>
#include<vector>

using namespace std;

struct ListNode {
	int val;
	ListNode* next;

	ListNode(int x):val(x),next(nullptr){}
};

ListNode* find_cross(ListNode* a1, ListNode* b1) {
	ListNode* A = a1;
	ListNode* B = b1;

	while (A != B) {
		//注意，当A遍历完后必须从传入的链表赋值重新开始，否则指针的位置不一样
		//A = A != nullptr ? A->next : B;
		//B = B != nullptr ? B->next : A;
		A = A != nullptr ? A->next : b1;
		B = B != nullptr ? B->next : a1;
	}
	return A;
}

int main() {
	ListNode* a1 = new ListNode(1);
	a1->next = new ListNode(2);
	a1->next->next = new ListNode(4);
	a1->next ->next->next= new ListNode(5);
	a1->next ->next->next->next= new ListNode(6);

	ListNode* b1 = new ListNode(11);
	b1->next = new ListNode(22);
	b1->next->next = new ListNode(43);
	b1->next->next->next = a1->next->next->next;

	ListNode* ans;
	ans=find_cross(a1, b1);

	cout << ans->val << endl;
}