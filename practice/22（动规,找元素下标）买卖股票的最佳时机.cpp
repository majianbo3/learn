#include<iostream>
#include<vector>
#include<iterator>
#include<algorithm>
using namespace std;

int main() {
    
    vector<int>prices = { 7,6,4,3,1 };
    int cost = INT_MAX;
    int profit = 0;

    for (int s : prices) {
        cost = min(cost, s);
        profit = max(profit, s - cost);
        cout << profit << endl;
    }

    //��һʱ��̫�ã�leecode�޷�ȫ��ͨ��
	//int gainings = 0;
 //   int min = 0,head = 1;

 //   for (int i = 0; i < prices.size(); i++) {
 //       while (i !=head && head<prices.size()) {
 //           //����������۳����
 //           if (prices[i] > prices[head])
 //               head++;
 //           else {
 //               gainings = max(gainings, prices[head] - prices[i]);
 //               head++;
 //           }
 //       }
 //       head = i + 2;
 //   }
 //   cout << gainings << endl;

    ////vector<int>::iterator biggest = max_element(prices.begin(), prices.end());
    ////cout << *biggest << endl;

    /*int a[] = { 3, 6, 8, 2 };
    int len = sizeof(a) / sizeof(int);*/
    //*Ϊ��ȡ��ַ�ڴ�ռ��Ԫ��
    //cout << *max_element(a, a + len) << endl;//8//������Ԫ��
    //cout << max_element(a, a + len) << endl;//�����Ϊ���ֵ�ĵ�ֵַ
    //cout << max_element(a, a + len) - a << endl;//2 //���Ԫ�ص��±�
    //cout << *min_element(a, a + len) << endl;//2


}