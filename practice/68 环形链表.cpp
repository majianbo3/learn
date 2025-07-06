#include<iostream>

using namespace std;

struct Listnode {
	int val;
	Listnode* next;
	Listnode(int x):val(x),next(nullptr){}
};

void judge_rotate(Listnode* l1) {
	Listnode* fast = l1;
	Listnode* tail = l1;

	while (tail != nullptr && tail->next != nullptr) {
		fast = fast->next;
		tail = tail->next->next;
		if (fast == tail)
		{
			cout << "ok" << endl;
			break;
		}

	}
}

int main() {
	Listnode* l1 = new Listnode(1);
	l1->next = new Listnode(2);
	l1->next->next = new Listnode(3);
	l1->next->next->next = new Listnode(4);

	judge_rotate(l1);

}