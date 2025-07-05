#include<iostream>
#include<vector>
using namespace std;


struct ListNode
{
    int x;
    ListNode* next;

    ListNode(int x) :x(x),next(nullptr){}
};

ListNode* create_list(const vector<int>& nums) {


    ListNode* head = nullptr;
    ListNode* tail = nullptr;

    for (int num : nums) {
        //�������ڵ��׸����ֶ��������ֵ������һ��ת���Ĺ���
        ListNode* node = new ListNode(num);
        if (!head)
            head = node;
        else
            tail->next = node;

        //����tail��ֵ
        tail = node;
    }
    return head;

}

class Solution {
public:
    ListNode* Middle(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;

        while (fast != nullptr && fast->next != nullptr) {
            fast = fast->next->next;
            slow = slow->next;
        }

        return slow;
    }

};

int main()
{

    vector<int> num = { 1,2,6,3 };

    ListNode* ln = create_list(num);

    Solution solution;

    ListNode* result = solution.Middle(ln);

    cout << result->x << endl;


    //����˫ָ�������
    //class Solution {
    //public:
    //    ListNode* middleNode(ListNode* head) {
    //        ListNode* fast = head, * slow = head;
    //        while (fast != nullptr && fast->next != nullptr) {
    //            fast = fast->next->next;
    //            slow = slow->next;
    //        }
    //        return slow;
    //    }
    //};

    //���ߣ�Krahets
    //    ���ӣ�https ://leetcode.cn/problems/middle-of-the-linked-list/solutions/1646119/by-jyd-aphd/
    //��Դ�����ۣ�LeetCode��
    //    ����Ȩ���������С���ҵת������ϵ���߻����Ȩ������ҵת����ע��������
}