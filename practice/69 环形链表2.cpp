#include<iostream>

#include<unordered_set>
using namespace std;

//需要找到环形链表的环的几个入口



struct Listnode {
	int val;
	Listnode* next;

	Listnode(int x):val(x),next(nullptr){}
};

void find_cricleFirst(Listnode* l1) {
	Listnode* head = l1;
	Listnode* tail = l1;

	while (tail != nullptr && tail->next != nullptr) {
		head = head->next;
		tail = tail->next->next;
		if (head == tail)
			break;
	}

	tail = l1;
	/*
为什么能这样找到起点？​​

设链表头到环起点的距离为 a，环起点到相遇点的距离为 b，环长度为 c。
第一次相遇时，slow 走了 a + b，fast 走了 a + b + k*c（k 是快指针绕环的圈数）。
因为 fast 速度是 slow 的 2 倍，所以 2(a + b) = a + b + k*c → a = k*c - b。
​​结论​​：从链表头走 a 步，和从相遇点走 k*c - b 步，都会到达环起点
*/
	while ((head != tail)) {
		head = head->next;
		tail = tail->next;
	}
	cout << tail->val << endl;
}

int main() {
	Listnode* l1 = new Listnode(1);
	l1->next = new Listnode(2);
	l1->next->next = new Listnode(3);
	l1->next->next->next = new Listnode(4);
	l1->next->next->next->next = l1->next->next;

	find_cricleFirst(l1);
}