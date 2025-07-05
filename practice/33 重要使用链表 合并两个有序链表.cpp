#include<iostream>

using namespace std;

int main() {
    ListNode* mergeTwoLists(ListNode * list1, ListNode * list2) {
        auto dummy = new ListNode(); // 用哨兵节点简化代码逻辑
        auto cur = dummy; // cur 指向新链表的末尾
        while (list1 && list2) {//list1和list2都已经进行了下一个值的更新，故不用判断下一个值
            if (list1->val < list2->val) {
                cur->next = list1; // 把 list1 加到新链表中
                list1 = list1->next;
            }
            else { // 注：相等的情况加哪个节点都是可以的
                cur->next = list2; // 把 list2 加到新链表中
                list2 = list2->next;
            }
            cur = cur->next;//将每次迭代的数据更新以此来进行下一次存储
        }
        cur->next = list1 ? list1 : list2; // 拼接剩余链表
        return dummy->next;//也就是cur所进行迭代的数据，第八行的代码地址一样，数据一样

        作者：灵茶山艾府
            链接：https ://leetcode.cn/problems/merge-two-sorted-lists/solutions/2373691/liang-chong-fang-fa-die-dai-di-gui-pytho-wf75/
        来源：力扣（LeetCode）
            著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
}