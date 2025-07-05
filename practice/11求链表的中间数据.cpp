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
        //将数组内的首个数字定义成链表值，这是一个转换的过程
        ListNode* node = new ListNode(num);
        if (!head)
            head = node;
        else
            tail->next = node;

        //更新tail的值
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


    //根据双指针来输出
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

    //作者：Krahets
    //    链接：https ://leetcode.cn/problems/middle-of-the-linked-list/solutions/1646119/by-jyd-aphd/
    //来源：力扣（LeetCode）
    //    著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
}