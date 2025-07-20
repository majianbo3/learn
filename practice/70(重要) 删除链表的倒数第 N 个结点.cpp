#include<iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode* next;

	ListNode(int x) :val(x), next(nullptr) {};
};

//��⣺����ͬһ�������ڵ�ָ�룬��Զ�ǵ�ַ����ֵ������������Ҳ�ǵ�ַ��
//������������ֵ������ԭʼ������ʹδ���������ص�ֵҲ�ǲ������
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

	//����dummyԤ��Ҫɾ��ͷ�ڵ�
	ListNode* dummy = new ListNode(0);
	dummy->next = head;
	ListNode* l1 = dummy;

	//��ʱ���㳤�ȣ�i��Ҫ��1��ʼ ����Ϊ����dummy i��0��ʼ,���뵽Ҫɾ����ǰһ������Ȼɾ����ɾ����ַ�������������
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