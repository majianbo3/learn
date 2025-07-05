#include<iostream>
#include<stack>
#include<vector>
#include<algorithm>
using namespace std;



int main() {
	vector<int>height = { 0,1,0,2,1,0,1,3,2,1,2,1 };
	int area = 0;
	stack<int>st;
	st.push(height[0]);

	for (int i = 1; i < height.size(); i++) {
		
		if (height[i] <= height[st.top()]) {
			st.push(i);
		}
		else {
			while(!st.empty()&&height[i]>height[st.top()])
			{
				int mid = height[st.top()];
				st.pop();

				if (!st.empty()) {
					int h = min(height[i], height[st.top()]) - mid;
					int w = i - st.top() - 1;
					area += h * w;
				}
			}

			st.push(i);
		}
	}

	cout << area << endl;
}







