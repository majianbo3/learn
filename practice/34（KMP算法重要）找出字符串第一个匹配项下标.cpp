#include<iostream>
#include<vector>
using namespace std;
/*
˼·��KMP�㷨��������ǰ��׺��
�ҳ��ַ����е�һ��ƥ������±�
�ı�����aabaabaaf
ģʽ����aabaaf
KMP�㷨��BF�㷨��ͬ�ĵط���
    ���ҵ���ƥ��ĵط���BF�㷨ֱ�ӻ��˵�ģʽ����ͷ����ƥ�䣻
    ��KMP�㷨ֻ�û��˵�����ǰ��׺ֵָ���ģʽ��λ�ã���ģʽ���е� b����
                                ����ƥ�䣬Ч��Ҫ�ߺܶ�
���ȷ���� b ���λ�ã�
    ����ǰ׺��next ���飩
        ǰ׺�����������һ���ַ��������Ե�һ���ַ���ͷ�������Ӵ�
        ��׺����������һ���ַ������������һ���ַ���β�������Ӵ�
        eg��ģʽ�� aabaaf ��ǰ׺���������Ϊ�ҶԳ�Ԫ�صĸ��������û�������⣩
            ǰ׺    next����ֵ
            a       0
            aa      1
            aab     0
            aaba    1
            aabaa   2
            aabaaf  0
    ǰ׺���ֵΪ a a b a a f
                0 1 0 1 2 0
    ��ƥ��ʱ����ƥ�䵽 f ʱ���ֲ�ƥ�䣬���Ǿ�ȥ�Ҳ�ƥ���Ԫ�ص�ǰһ��Ԫ�أ�a��
    ��Ӧ��ǰ׺���е�ֵ��2��
    ����ǰ׺������ԣ���ƥ��Ԫ�ص�ǰһԪ�ض�Ӧ��ǰ׺���е�ֵ��������ǰ��׺
    ������ next �������ҵ��±�Ϊ 2 ��Ԫ�أ���ģʽ���е� b��
        ���ͣ����ҵ�����ǰ��׺��ֵ��Ϊ 2 ��
        ��ʾ�ڲ�ƥ��Ԫ�ص�ǰ����һ����׺ aa ��������ǰ��Ҳ��һ��������ȵ�ǰ׺ aa ��
        ��Ȼ�������׺�ĺ��淢�ֲ�ƥ���ˣ���ô��Ҫ��������ȵ�ǰ׺�ĺ������ƥ�䣬
        Ҳ�����ҵ���ǰ�� aab ��� b

class Solution
{
private:
    void getNext(int* next, const string& s) // ��� next ����
    {
        int j = 0;
        next[0] = 0; // ǰ׺�����Ԫ��һ���� 0 ����Ϊ�ַ�������λû�ж�Ӧ��ǰ��׺
        for (int i = 1; i < s.size(); i++)
        {
            while (j > 0 && s[i] != s[j]) // jҪ��֤����0����Ϊ������ȡj-1��Ϊ�����±�Ĳ���
            {
                j = next[j - 1]; // ��ǰһλ�Ķ�Ӧ�Ļ���λ��
            }
            if (s[i] == s[j])
            {
                j++;
            }
            next[i] = j; // ���� next �����ֵ
        }
    }
public:
    int strStr(string haystack, string needle)
    {
        if (needle.size() == 0)
        {
            return 0;
        }
        int next[needle.size()]; // ���� next ���飨ǰ׺��
        getNext(next, needle); // ��� next ����
        int j = 0; // j ָ��ǰ׺ĩβλ��
        for (int i = 0; i < haystack.size(); i++) // i ָ���׺ĩβλ��
        {
            while (j > 0 && haystack[i] != needle[j]) // ǰ��׺��ƥ��ʱ
            {
                j = next[j - 1]; // j ���˵� next ����ǰһ��λ����ָ���ֵ
            }
            if (haystack[i] == needle[j]) // ǰ��׺ƥ��ʱ
            {
                j++; // i��j ���ƣ�i �ĺ����� for ѭ����
            }
            if (j == needle.size()) // ��� ģʽ�� ������
            {
                return i - needle.size() + 1;
            }
        }
        return -1; // û�ҵ�
    }
};

���ߣ�NULL
���ӣ�https ://leetcode.cn/problems/find-the-index-of-the-first-occurrence-in-a-string/solutions/2415774/xiao-bai-ha-ha-ha-ha-yi-xing-dai-ma-by-t-dg0z/
��Դ�����ۣ�LeetCode��
����Ȩ���������С���ҵת������ϵ���߻����Ȩ������ҵת����ע��������
*/



int main() {
	//string haystack = "sadbutsad", needle = "sad";
	//string haystack = "leetcode", needle = "leeto";
	//string haystack = "a", needle = "a";
	string haystack = "mississippi", needle = "issip";
    vector<int>next(needle.size(), 0);
    int j = 0;

    next[0] = 0;
    for (int i = 1; i < needle.size(); i++)
    {
        while (j > 0 && needle[i] != needle[j]) // jҪ��֤����0����Ϊ������ȡj-1��Ϊ�����±�Ĳ���
        {
            j = next[j - 1]; // ��ǰһλ�Ķ�Ӧ�Ļ���λ��
        }
        if (needle[i] == needle[j])
        {
            j++;
        }
        next[i] = j; // ���� next �����ֵ
    }
    //for (auto row : next)
    //    cout << row << " ";
    //cout << endl;
    // 
    int haystack_len = 0;
    for (int i = 0; i < haystack.size(); i++) {
        while (haystack_len > 0 && haystack[i] != needle[haystack_len]) {
            haystack_len = next[haystack_len - 1];
        }
        if (haystack[i] == needle[haystack_len])
            haystack_len++;
        if (haystack_len == needle.size())
            return i - needle.size() + 1;
    }
    return -1;
	//int len = haystack.size();
	//int len1 = needle.size();
	//int ans = -1,head = 0,idx=0;
	//for (int i = 0; i < len+1; i++) {
	//	if (head < len1 && needle[head] == haystack[i]) {
	//		if (head == 0)
	//			idx = i;
	//		head++;
	//	}
	//	else if (head == len1 )
	//		return idx;
	//	else {
	//		head = 0;
	//		//i = idx + 1;
	//	}
	//	
	//}
	//	return ans;
}