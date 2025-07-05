#include<iostream>
#include<list>
#include<unordered_map>
#include<chrono>
#include<thread>
#include<string>
#include<algorithm>
using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x):val(x),next(nullptr){}
};

void revese_Knode(ListNode* root, int k) {
	ListNode* cur = root;
	ListNode* pre = nullptr;
	while (k > 0 ) {
		ListNode* next = cur->next;
		cur->next = pre;
		pre = cur;
		cur = next;
		k--;
	}
	if (cur) {
		root->next = cur;
	}
		

	while (pre != nullptr) {
		cout << pre->val << endl;
		pre = pre->next;
	}
}

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x):val(x),left(nullptr),right(nullptr){}
};

void tree_reverse(TreeNode* root, vector<int>& ans) {
	if (root) {
		tree_reverse(root->left, ans);
		tree_reverse(root->right, ans);
		ans.push_back(root->val);
	}
}

vector<int>reverse_tree(TreeNode* root) {
	vector<int>ans;
	tree_reverse(root, ans);
	return ans;
}

void front_tree(TreeNode* root) {
	if (root) {
		cout << root->val << endl;

		if (root->left) front_tree(root->left);
		if (root->right) front_tree(root->right);
	}
}

int provition(vector<int>& nums, int left, int right) {
	
	int provic = nums[left];

	while (left < right) {
		while (left < right && nums[right] > provic)
			right--;
		nums[left] = nums[right];

		while (left < right && nums[left] < provic)
			left++;
		nums[right] = nums[left];
	}
	nums[left] = provic;
	return left;
}

void quickSort(vector<int>& nums,int left,int right) {
	if (left < right) {
		int provic = provition(nums,left, right);
		quickSort(nums, left, provic - 1);
		quickSort(nums,  provic +1,right);
	}

}

void marix() {

	vector<vector<int>>marix = {
		{1,2,3},
		{3,5,7},
		{1,2,4},
	};

	int ans = 0;

	for (auto row : marix) {
		for (auto col : row) {
			ans = max(ans, col);
		}
	}

	cout << ans << endl;
	int k = 2;
	vector<vector<int>>marix1(k, vector<int>(k));

	for (int i = 0; i < k; i++) {
		for (int j = 0; j < k; j++) {
			cin >> marix1[i][j];
		}
	}

	for (auto row : marix1) {
		for (auto col : row) {
			cout << col << " ";
		}
		cout << endl;
	}
}
int main() {

	/*ListNode* root = new ListNode(1);
	root->next = new ListNode(2);
	root->next->next = new ListNode(3);
	root->next->next->next = new ListNode(4);
	root->next ->next->next->next= new ListNode(5);
	int k = 3;

	revese_Knode(root, k);*/

	//TreeNode* root = new TreeNode(1);
	//root->left = new TreeNode(2);
	//root->right = new TreeNode(3);
	//root->left->left = new TreeNode(4);
	//root->left->right = new TreeNode(5);
	//root->right->left = new TreeNode(6);
	//vector<int> ans;
	////后续遍历
	////ans =reverse_tree(root);
	////前序遍历
	// //front_tree(root);
	////for (auto c : ans)
	////	cout << c << " ";
	////cout << endl;
	//vector<int>nums = { 6,4,2,5,1,7 };
	//quickSort(nums,0,nums.size()-1);
	//for (auto c : nums)
	//	cout << c << "";
	//cout << endl;
	vector<string> str = { "eat", "tea", "tan", "ate", "nat", "bat" };

	unordered_map<string, vector<string>>v;

	for (auto s : str) {
		string s1 = s;
		sort(s1.begin(), s1.end());

		v[s1].push_back(s);
	}

	vector<vector<string>>ans;

	for (auto pair : v)
		ans.push_back(pair.second);

	for (auto row : ans) {
		for (auto col : row)
			cout << col << " ";
		cout << endl;
	}

}