#include<iostream>
#include<vector>
#include<unordered_map>
#include<string>
#include<algorithm>
using namespace std;


int find_child_str(const string& str) {

	vector<int>map(128,0);
	int head = 0;
	int max_len = 0;
	
	for (int i = 0; i < str.size(); i++) {
		//head=max(head,map(str[i]))

		head = max(head, map[str[i]]);
		map[str[i]] = i + 1;

		max_len = max(max_len, i - head + 1);

	}
	return max_len;

}

void max_string() {
	string s = "abcdadec";

	int ans = find_child_str(s);
	cout << ans<<endl;
}


#include<cctype>

string captial_first(string target) {
	target[0] = toupper(target[0]);

	return target;
}

string string_process(const string& s,string target) {
	
	size_t pos = s.find(target);
	if (pos != string::npos) {
		return captial_first(target);
	}
	return "";
}

void easy_string() {
	string s = "hello,zhangsan";
	string target = "zhangsan";
	string ans = string_process(s,target);
	cout << ans << endl;
}

string string_big(string& s1) {
	int l1 = s1.size();
	
	for (int i = 0; i < l1; i++) {
		s1[i] = toupper(s1[i]);
	}
	return s1;
}
void big_string() {
	string s = "hello,zhangsan";
	string target = "zhangsan";
	string ans = string_big(s);
	cout << ans << endl;
}

int find_maxFirst(vector<int>nums, int target) {
	int middle = 0;
	int left = 0, right = nums.size()-1;

	while(left<=right) {
		middle = left + (right-left ) / 2;

		if (nums[middle] < target) {
			left = middle + 1;
		}
		else {
			right = middle-1;
		}

	}
	return left;

}

void num_process() {
	//vector<int>nums = { 1,2,3,5,6,7 };
	vector<int>nums = { 1,3,5,6,7 };
	int target = 3;

	int ans = find_maxFirst(nums, target);
	cout << ans << endl;
}

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x):val(x),next(nullptr){}
};

ListNode* Join_list(ListNode* s1, ListNode* s2) {
	ListNode dummy =  ListNode(0);
	ListNode* tail = &dummy;
	ListNode* l1 = s1;
	ListNode* l2 = s2;

	while (l1 != nullptr && l2 != nullptr) {
		if (l1->next!=nullptr &&l1->val == l1->next->val)
			l1 = l1->next;
		if (l2->next!=nullptr&& l2->val == l2->next->val)
			l2 = l2->next;

		if ( l1->val <= l2->val) {
			if (l1->val == tail->val)
				l1 = l1->next;
			tail->next = l1;
			tail = l1;
			l1 = l1->next;
			//tail = tail->next;
		}
		else {
			if (l2->val == tail->val ) {
				l2 = l2->next;
			}
			if(l1->val > l2->val)
			{
				tail->next = l2;
				tail = l2;
				l2 = l2->next;
			}
			//tail = tail->next;
		}


	}
	while (l1 != nullptr) {
		if (l1->val > tail->val) {
			tail->next = l1;
			tail = l1;
			l1 = l1->next;
		}
		else
			l1 = l1->next;
	}
	while (l2 != nullptr) {
		if (l2->val > tail->val) {
			tail->next = l2;
			tail = l2;
			l2 = l2->next;
		}
		else
			l2 = l2->next;
	}

	tail->next = nullptr;
	return dummy.next;
}


void list_join() {
	ListNode* l1 = new ListNode(1);
	l1->next = new ListNode(1);
	l1->next->next = new ListNode(2);
	l1->next->next->next = new ListNode(3);

	ListNode* l2 = new ListNode(2);
	l2->next = new ListNode(3);
	l2->next->next = new ListNode(4);

	ListNode* ans = Join_list(l1, l2);

	while (ans != nullptr) {
		cout << ans->val << endl;
		ans = ans->next;
	}

}

bool judge_rotate(ListNode* l1) {
	ListNode* low = l1;
	ListNode* fast = l1;

	while (fast != nullptr&&fast->next!=nullptr) {
		low = low->next;
		fast = fast->next->next;

		if (low == fast)
			return true;
	}
	return false;
}

void list2list() {
	ListNode* l1 = new ListNode(1);
	l1->next = new ListNode(1);
	l1->next->next = new ListNode(2);
	l1->next->next->next = new ListNode(3);
	l1->next->next->next->next = l1->next;

	bool ans =judge_rotate(l1);
	cout << "has cycle " <<(ans ? "yse" : "no" )<< endl;
}

int tofind(string s, int left, int right) {
	int L = left;
	int R = right;
	
	while (L >= 0 && s[L] == s[R] && R < s.size()) {
		L--;
		R++;
	}
	return R - L - 1;
}


string find_huiwen(string s) {
	int len = 0,end=0,start=0;
	int l2 = 0;
	for (int i = 0; i < s.size(); i++) {
		int l1 = tofind(s, i, i);
		if (i + 1 < s.size())
			 l2 = tofind(s, i, i + 1);
		else
			 l2 = 0;

		len = max(l1, l2);
		if (len > end - start) {
			start = i - (len -1)/ 2;
			end = i + (len+1) / 2;
		}
		if (start < 0) {
			start = abs(start);
		}
	}

	return s.substr(start, end);

}
void huiwen() {
	string s = "baacd";

	string ans = find_huiwen(s);
	cout << ans << endl;
	
}

vector<int>sort_bubble(vector<int>nums) {
	for (int i = 0; i < nums.size(); i++) {
		for (int j = 0; j < nums.size() - i-1; j++) {
			if (nums[j + 1] < nums[j])
				swap(nums[j], nums[j + 1]);
		}
	}
	return nums;
}

void bubblesort() {
	vector<int>nums = { 1,7,9,3,4 };

	vector<int>ans = sort_bubble(nums);
	for (auto s : ans)
		cout << s << endl;
}

int provition(vector<int>& nums, int low, int high) {
	int provit = nums[low];

	while (low < high) {

		while (low<high && nums[high]>provit)
			high--;
		nums[low] = nums[high];

		while (low < high && nums[low] < provit)
			low++;
		nums[high] = nums[low];
	}

	nums[low] = provit;

	return low;
}

void quicksort(vector<int>& nums, int low, int high) {
	if (low < high) {
		int provit = provition(nums, low, high);
		quicksort(nums, low, provit - 1);
		quicksort(nums, provit + 1, high);
	}
}

void quicksortMain() {
	vector<int>nums = { 3,4,2,8,5,1,9,6 };

	quicksort(nums, 0, nums.size());
}
string tochinese(int num) {
	if (num == 0) return "零";

	string digits = "零一二三四五六七八九";
	vector<string> units = { "", "十", "百", "千", "万", "十", "百", "千", "亿" };
	string result;

	bool hasZero = false;  // 用于处理连续的零
	int index = 0;  // 用于记录当前位的单位

	while (num > 0) {
		int digit = num % 10;  // 取当前位的数字
		num /= 10;  // 去掉当前位

		if (digit != 0) {
			if (hasZero) {
				result = digits[0] + result;  // 添加“零”
				hasZero = false;
			}
			result = digits[digit] + units[index] + result;  // 添加数字和单位
		}
		else {
			hasZero = true;  // 标记连续的零
		}

		index++;
	}

	// 去掉多余的“零”
	if (result[0] == digits[0]) result = result.substr(1);

	// 特殊处理“十”和“一十”的情况
	if (result.find("一十") == 0) result = result.substr(1);
	
	return result;
}

void chinese() {
	int num = 1234;

	string ans =tochinese(num);
	cout << ans << endl;
}

#include<stack>
class Stack {
private:
	stack<int>stack1;
	stack<int>stack2;

public:
	void enqueue(int i) {
		stack1.push(i);
	}

	void dequeue() {
		while (!stack1.empty()) {
			stack2.push(stack1.top());
			stack1.pop();
		}
		if (!stack2.empty()) {
			cout << "dequeue " << stack2.top() << endl;
			stack2.pop();
		}
		else {
			cout << "no num" << endl;
		}
	}
};
void use_stack() {
	Stack stack;
	stack.enqueue(1);
	stack.enqueue(2);
	stack.enqueue(3);
	stack.dequeue();
	stack.dequeue();
	stack.dequeue();
}

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;

	TreeNode(int x) :val(x), left(nullptr), right(nullptr) {}
};

void digui(TreeNode* root) {

	if (root) {
		//TreeNode* node = root;
		cout << root->val << endl;

		if (root->left)digui(root->left);
		if (root->right)digui(root->right);
	}
}


void diedai(TreeNode* root) {
	stack<TreeNode*>stack;
	stack.push(root);

	while (!stack.empty()) {
		TreeNode* node = stack.top();
		cout << node->val << endl;
		stack.pop();

		if (node->right)stack.push(node->right);
		if (node->left)stack.push(node->left);

	}
}


void two_tree() {
	/*
		  1
	  2        3
   4     5   6   7
	*/
	TreeNode* tree = new TreeNode(1);
	tree->left = new TreeNode(2);
	tree->right = new TreeNode(3);
	tree->left->left = new TreeNode(4);
	tree->left->right = new TreeNode(5);
	tree->right->left = new TreeNode(6);
	tree->right->right = new TreeNode(7);

	//digui(tree);
	diedai(tree);



}

void reverse_list(ListNode* root) {
	ListNode* pre = nullptr;
	ListNode* cur = root;

	while (cur != nullptr) {
		ListNode* next = cur->next;
		cur->next = pre;
		pre = cur;
		cur = next;

	}
	while (pre)
	{
		cout << pre->val << endl;
		pre = pre->next;
	}
}

void rever_listmain() {

	ListNode* root = new ListNode(1);
	root->next = new ListNode(2);
	root->next->next = new ListNode(3);
	root->next->next->next = new ListNode(4);
	root->next->next->next->next = new ListNode(5);

	reverse_list(root);
}


void min_distance() {
	vector<int>nums = { 2,3,1,1,4 };

	int cur = 0, next = 0,ans=0;
	
	for (int i = 0; i < nums.size(); i++) {
		next = max(next, nums[i] + i);

		if (i == cur) {
			if (i != nums.size() - 1) {
				ans++;
				cur = next;
				if (next >= nums.size() - 1)
					break;
			}
			else
				break;
		}
	}


}



#define MAXNUM( a, b) (a>b?a:b)

//template<typename T>
//T maxNum(T a, T b) {
//	return (a>b?a:b)
//}



#include<list>

class Cache {
private:
	list<int>keys;
	int capacity;
	unordered_map<int, pair<int, list<int>::iterator>>cache;

public:
	Cache(int x):capacity(x){}
	void put(int key, int value) {
		if (keys.size() >= capacity && cache.find(key) == cache.end()) {
			auto last = keys.back();
			cache.erase(cache.find(last));
			keys.pop_back();
		}
		cache[key] = { value,keys.insert(keys.begin(),key) };
	}

	int get(int key) {
		if (cache.find(key) == cache.end())
			return -1;

		auto it = cache.find(key);
		keys.erase(it->second.second);
		keys.push_front(key);
		it->second.second = keys.begin();
		return it->second.first;
	}
};

#include<chrono>
#include<thread>

class CacheTime {
private:
	int timeout = 0;
	int capacity = 0;
	list<int>keys;
	unordered_map<int, pair<int, list<int>::iterator>>cache;
	unordered_map<int, chrono::steady_clock::time_point>timestamps;

	void checktime() {
		auto now = chrono::steady_clock::now();
		for (auto it = cache.begin(); it != cache.end();) {
			auto latest = chrono::duration_cast<chrono::seconds>(now - timestamps[it->first]);

			if (latest.count() >= timeout) {
				keys.erase(it->second.second);
				timestamps.erase(it->first);
				it = cache.erase(it);
			}
			else
				it++;
		}
	}

public:
	CacheTime(int x,int y):capacity(x),timeout(y){}

	void put(int key, int value) {
		checktime();
		if (keys.size() >= capacity && cache.find(key) == cache.end()) {
			auto last = keys.back();
			cache.erase(cache.find(last));
			keys.pop_back();
			timestamps.erase(last);
		}
		cache[key] = { value,keys.insert(keys.begin(),key) };
		timestamps[key] = chrono::steady_clock::now();

	}

	int get(int key) {
		checktime();
		if (cache.find(key) == cache.end())
			return -1;

		auto it = cache.find(key);
		keys.erase(it->second.second);
		keys.push_front(key);
		it->second.second = keys.begin();
		timestamps[key] = chrono::steady_clock::now();
	}
};

void LRU_cache() {
	Cache cache(2);

	cache.put(1, 11);
	cache.put(2, 22);
	cache.put(3, 33);

	cout << cache.get(2) << endl;
	cout << cache.get(1) << endl;
	cout << "cache time start" << endl;

	CacheTime cachetime(2, 1);
	cachetime.put(1, 11);
	cachetime.put(2, 22);
	cachetime.put(3, 33);
	cout << cachetime.get(1) << endl;

	this_thread::sleep_for(chrono::seconds(2));

	cout << cachetime.get(3) << endl;
}

int main() {
	//max_string();
	//easy_string();
	//big_string();
	//num_process();
	//list_join();
	//list2list();
	//huiwen();
	//bubblesort();
	//quicksortMain();
	//chinese();
	//use_stack();
	//two_tree();
	//rever_listmain();
	//min_distance();
	//LRU_cache();
}