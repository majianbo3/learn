#include<iostream>
#include<vector>
using namespace std;

/*
���˼·��
            1�������������ַ���ֵ��Ϊ0�������m��
            2�������ַ�����������
            3��������ظ������� ���ڴ����   m[s[i]] = i + 1; ��Ĭ�ϻ�ָ���ظ������һ��λ��
            �Դ���ʵ�ֻ�������ȷ�ϲ��ظ��ĳ���

*/

int main()
{
	string s = "abcabcbb";

    vector<int> m(128, 0);
    //����󳤶�
    int maxlen = 0;
    //head��ʾ��������ߵ���ĸ��ţ���������ظ��ģ�����������ͬ����ĸa��
    // ��һ��a��Ͱ����m[s[i]]��a+1��ʾa����һ��λ��
    //��ô�ڶ���a����ʱ��head��=a+1Ҳ����max(head,m[s[i]])��
    //ȥ���˴�������һ��a����֤���������ظ���ĸ
    int head = 0;
    //�����ַ���
    
    for (int i = 0; i < s.size(); i++) {

        head = max(head, m[s[i]]);

        m[s[i]] = i + 1;

        maxlen = max(maxlen, i - head + 1);


    }
    
    
    
    
    
    
    
    
    
    for (int i = 0; i < s.size(); i++) {
        ////�޸�����ߵ���ĸ���head
        //cout << "û��ǰ��"<<head << endl;
        head = max(head, m[s[i]]);
   /*     cout << "�ĺ�" << head << endl;
        cout << "m��" << m[s[i]] << endl;
        cout << "s[i]" << s[i] << endl;*/
        //��ǰ��ĸ��Ӧ��ASCII��Ͱ�����һ��λ��(i+1)�����ڸ���head
        m[s[i]] = i + 1;//��Ҫ��������head��λ��
        //���³���
        maxlen = max(maxlen, i - head + 1);
        cout << "���º�ĳ���" << maxlen << endl;
    }

    cout << "���յĳ���" << maxlen << endl;
    //vector<int> v;
    //for (int i = 0; i < s.size(); i++)
    //{
    //    for (int j = i + 1; j < s.size(); j++)
    //    {
    //        if (s[i] == s[j])
    //        {
    //          // cout << j << endl;
    //            //return j;
    //            // break;
    //            v.push_back(j);
    //            
    //        }
    //    }
    //}
	//vector<int>v = { 1,2,3,4 };
	//auto max = max_element(v.begin(), v.end());
	//cout << *max<< endl;
}
/*   ��2
* 
        if(s.size() == 0) return 0;
        unordered_set<char> lookup;
        int maxStr = 0;
        int left = 0;
        for(int i = 0; i < s.size(); i++){
         //��unordered_set�������Ԫ�ش��ڣ�`find`����������ָ���Ԫ�صĵ�������
         //���Ԫ�ز����ڣ�`find`���������ؼ��ϵ�β�����������`lookup.end()`��
         //�����ڸ�Ԫ��
            while (lookup.find(s[i]) != lookup.end()){
                lookup.erase(s[left]);
                left ++;
            }
            //i��ʾ�ұߵĻ�����left��ʾ����ߵĻ�����+1����Ϊ��0��ʼ
            maxStr = max(maxStr,i-left+1);
            lookup.insert(s[i]);
    //}
        return maxStr;

    }

���ߣ�powcai
���ӣ�https://leetcode.cn/problems/longest-substring-without-repeating-characters/solutions/3982/hua-dong-chuang-kou-by-powcai/
��Դ�����ۣ�LeetCode��
����Ȩ���������С���ҵת������ϵ���߻����Ȩ������ҵת����ע��������
*/