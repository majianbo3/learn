#include<iostream>

#include<vector>
using namespace std;

//��������������� �� ���ڵ� �� ������
/*

���� inorderTraversal(root) ��
res ��ʼ��Ϊ []��
���� inorder(1, res)
2.1 ���� inorder(2, res)
2.1.1 ���� inorder(4, res)
- ��Ϊ�շ���
- res.push_back(4) �� res=[4]
- ��Ϊ�շ���
2.1.2 res.push_back(2) �� res=[4,2]
2.1.3 ���� inorder(5, res) �� ͬ��õ� res=[4,2,5]
2.2 res.push_back(1) �� res=[4,2,5,1]
2.3 ���� inorder(3, res) �� �õ� res=[4,2,5,1,3]
���� res �����أ�[4,2,5,1,3]����������������
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
    if (!root) {              // �� �ݹ���ڣ��ڵ�Ϊ����������
        return;
    }
    inorder(root->left, res); // �� �ȵݹ����������
    res.push_back(root->val); // �� ������ȫ��������󣬰ѵ�ǰ�ڵ�ֵ������
    inorder(root->right, res);// �� ���ݹ����������
}

// ���������û�ʵ�ʵ��õĽӿ�
vector<int> inorderTraversal(TreeNode* root) {
    vector<int> res;          // �� ׼��һ���� vector ��Ž��
    inorder(root, res);       // �� ���ø���������ʼ�ݹ�
    return res;               // �� ���ռ��õĽ�����ظ�������
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