#include<iostream>

using namespace std;


struct Listnode {
	int val;
	Listnode* next;
	Listnode(int x) :val(x), next(nullptr){}
};

Listnode* reverselist(Listnode* l1) {
	Listnode* pre = nullptr;

	while (l1 != nullptr ) {
		Listnode* next = l1->next;
		l1->next = pre;
		pre = l1;
		l1 = next;
	}
	return pre;
}
bool judgehuiwen(Listnode* l1) {
	Listnode* fast = l1;
	Listnode* slow = l1;
	while (fast != nullptr && fast->next != nullptr) {
		slow = slow->next;
		fast = fast->next->next;
	}

	//反转链表
	slow =reverselist(slow);

	Listnode* head = l1;
	//注意此时是slow如何是head，奇数时会出错
	while (slow != nullptr && slow->next != nullptr) {
		if (head->val == slow->val) {
			head = head->next;
			slow = slow->next;
		}else{
			return false;
		}
	}
	return true;
}

int main() {

	Listnode* head = new Listnode(1);

	head->next = new Listnode(2);
	head->next->next = new Listnode(3);
	head->next->next->next = new Listnode(2);
	head->next->next->next->next = new Listnode(1);

	bool ok =judgehuiwen(head);
	cout << "结果是" << (ok ? "yes" : "no") << endl;
}