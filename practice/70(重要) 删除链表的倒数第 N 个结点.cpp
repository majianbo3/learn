#include<iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode* next;

	ListNode(int x) :val(x), next(nullptr) {};
};

//理解：对于同一个函数内的指针，永远是地址，赋值给其他变量的也是地址，
//故其他变量对值操作后，原始变量即使未操作，返回的值也是操作后的
int get_len(ListNode* head) {
	int length = 0;

	while (head != nullptr) {
		length++;
		head = head->next;
	}
	return length;
}

ListNode* del_tailN(ListNode* head, int n) {
	int length = get_len(head);

	//加入dummy预防要删除头节点
	ListNode* dummy = new ListNode(0);
	dummy->next = head;
	ListNode* l1 = dummy;

	//此时计算长度，i需要从1开始 但因为引入dummy i从0开始,必须到要删除的前一个，不然删除会删除地址，导致链表断裂
	for (int i = 0; i < length - n ; i++)
		l1 = l1->next;

	ListNode* todel = l1->next;
	l1->next = l1->next->next;
	delete todel;
	return dummy->next;

}

void printList(ListNode* head) {
	while (head) {
		std::cout << head->val << " ";
		head = head->next;
	}
	std::cout << std::endl;
}
int main() {
	ListNode* l1 = new ListNode(1);
	l1->next = new ListNode(2);
	l1->next->next = new ListNode(3);
	l1->next->next->next = new ListNode(4);
	l1->next->next->next ->next= new ListNode(5);
	int n = 5;

	ListNode* ans=del_tailN(l1, n);
	printList(ans);
}