#include<iostream>

#include<vector>
using namespace std;

//中序遍历，左子树 → 根节点 → 右子树
/*

调用 inorderTraversal(root) 后：
res 初始化为 []。
进入 inorder(1, res)
2.1 进入 inorder(2, res)
2.1.1 进入 inorder(4, res)
- 左为空返回
- res.push_back(4) → res=[4]
- 右为空返回
2.1.2 res.push_back(2) → res=[4,2]
2.1.3 进入 inorder(5, res) → 同理得到 res=[4,2,5]
2.2 res.push_back(1) → res=[4,2,5,1]
2.3 进入 inorder(3, res) → 得到 res=[4,2,5,1,3]
最终 res 被返回：[4,2,5,1,3]，即中序遍历结果。
*/
struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

void inorder(TreeNode* root, vector<int>& res) {
    if (!root) {              // ① 递归出口：节点为空立即返回
        return;
    }
    inorder(root->left, res); // ② 先递归遍历左子树
    res.push_back(root->val); // ③ 左子树全部处理完后，把当前节点值加入结果
    inorder(root->right, res);// ④ 最后递归遍历右子树
}

// 主函数：用户实际调用的接口
vector<int> inorderTraversal(TreeNode* root) {
    vector<int> res;          // ⑤ 准备一个空 vector 存放结果
    inorder(root, res);       // ⑥ 调用辅助函数开始递归
    return res;               // ⑦ 把收集好的结果返回给调用者
}

int main() {
	TreeNode* t1 = new TreeNode(1);
	t1->left = new TreeNode(2);
	t1->left->left = new TreeNode(4);
	t1->left->right = new TreeNode(5);
	t1->right = new TreeNode(3);

	vector<int>ans=inorderTraversal(t1);

	for (auto a : ans)
		cout << a << " ";
	cout << endl;
}