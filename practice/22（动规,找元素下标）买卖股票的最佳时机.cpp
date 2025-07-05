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

    //法一时间太久，leecode无法全部通过
	//int gainings = 0;
 //   int min = 0,head = 1;

 //   for (int i = 0; i < prices.size(); i++) {
 //       while (i !=head && head<prices.size()) {
 //           //购买金额大于售出金额
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
    //*为获取地址内存空间的元素
    //cout << *max_element(a, a + len) << endl;//8//输出最大元素
    //cout << max_element(a, a + len) << endl;//输出的为最大值的地址值
    //cout << max_element(a, a + len) - a << endl;//2 //最大元素的下标
    //cout << *min_element(a, a + len) << endl;//2


}