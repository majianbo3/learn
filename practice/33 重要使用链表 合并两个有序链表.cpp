#include<iostream>

using namespace std;

int main() {
    ListNode* mergeTwoLists(ListNode * list1, ListNode * list2) {
        auto dummy = new ListNode(); // ���ڱ��ڵ�򻯴����߼�
        auto cur = dummy; // cur ָ���������ĩβ
        while (list1 && list2) {//list1��list2���Ѿ���������һ��ֵ�ĸ��£��ʲ����ж���һ��ֵ
            if (list1->val < list2->val) {
                cur->next = list1; // �� list1 �ӵ���������
                list1 = list1->next;
            }
            else { // ע����ȵ�������ĸ��ڵ㶼�ǿ��Ե�
                cur->next = list2; // �� list2 �ӵ���������
                list2 = list2->next;
            }
            cur = cur->next;//��ÿ�ε��������ݸ����Դ���������һ�δ洢
        }
        cur->next = list1 ? list1 : list2; // ƴ��ʣ������
        return dummy->next;//Ҳ����cur�����е��������ݣ��ڰ��еĴ����ַһ��������һ��

        ���ߣ����ɽ����
            ���ӣ�https ://leetcode.cn/problems/merge-two-sorted-lists/solutions/2373691/liang-chong-fang-fa-die-dai-di-gui-pytho-wf75/
        ��Դ�����ۣ�LeetCode��
            ����Ȩ���������С���ҵת������ϵ���߻����Ȩ������ҵת����ע��������
}