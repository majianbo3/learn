#include<iostream>
#include<vector>

using namespace std;

// ����1��ʹ�û��ݷ���˼·˼������ÿ��ѡ��һ������������ʱ�����Լ�
// ���ʣ�µ������ж��������еĿ��ܣ�
// �����Լ������ǰ��ѡ��������������������� remain_fac ��ʾ��
//  remain_fac = ʣ�µĴ�ѡ������Ľ׳ˡ�
// Ȼ�� remain_fac �� k ���д�С�Ƚϣ���С�� k ����˵����Ҫ��ĵ� k 
// �����в����� ��ǰѡ������ Ϊ��ͷ�����������У�ֱ������
// һ�εݹ鵽�׾����ҵ� �� k ������
// 

// �� n �Ľ׳� ����ֱ��ʹ�����飺factorial = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880}
int factorial(int n) {
    int res = 1;
    while (n > 0) {
        res *= n;
        n--;
    }
    return res;
}
// �ݹ�ʵ��
void dfs(vector<bool>& isUsed, string& res, int n, int k) {
    int res_len = res.size();
    if (res_len == n) {    // ������������ǰ�����Ѿ�����
        return;
    }
    int remain_fac = factorial(n - res_len - 1);  // ʣ�µ�����ȫ���еĸ���
    for (int i = 1; i <= n; ++i) {                  // ���� [1, n]
        if (isUsed[i]) {                            // ������ʹ�õ���
            continue;
        }
        if (remain_fac > 0 && remain_fac < k) {     // ʣ�µ�����ȫ���и���С�ڵ�ǰ k ��
                        //˵���� k �����п϶����ڵ�ǰ�ĵݹ������У�ֱ�������õݹ�
            k -= remain_fac;                      // ��֦
            continue;
        }
        res = res + static_cast<char>('0' + i);
        isUsed[i] = true;
        dfs(isUsed, res, n, k);
        // ��Ϊ��һ�εݹ�ֱ�ӵ�Ҷ�ӣ����Բ���Ҫ��ԭ״̬
    }
}


string getPermutation(int n, int k) {
    vector<bool> isUsed(n + 1, false);          // ���ڱ��ÿ�����Ƿ��ù�
    string res = "";                            // ���ڷ��صĽ����������

    dfs(isUsed, res, n, k);
    return res;
}


int main() {
	int n = 3, k = 3;

    getPermutation(n, k);
}