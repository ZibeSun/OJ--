#include<iostream>
using namespace std;
//���ڱ���˳����Һ���
//���ҳɹ��򷵻�Ԫ���������е�λ��
//����ʧ���򷵻�0
int Sequential_Search(int* item,int n,int key)
{
	int i = n;
	item[0] = key;

	while (item[i] != key)
		i--;

	return i;
}
int main()
{
	int n;
	int t;
	int key;
	while (cin >> n)
	{
		int* item = new int[n + 1];
		for (int i = 1; i <= n; i++)
		{
			cin >> item[i];
		}
		cin >> t;
		while (t--)
		{
			cin >> key;
			if (Sequential_Search(item, n, key) != 0)
				cout << Sequential_Search(item, n, key) << endl;
			else
				cout << "error" << endl;
		}
	}
}
/*
��Ŀ����
����һ�����к�Ҫ���ҵ���ֵ���ҳ���ֵ�ڶ����е�λ�ã�����λ�ô�1��ʼ
Ҫ��ʹ�ô��ڱ���˳������㷨
����
��һ������n����ʾ������n������
�ڶ�������n�����ݣ��������������ÿո����
����������t����ʾ��t��Ҫ���ҵ���ֵ
������������t����ֵ������t��
���
ÿ�����һ��Ҫ���ҵ���ֵ�ڶ��е�λ�ã�������Ҳ��ɹ�������ַ���error
��������
8 33 66 22 88 11 27 44 55 3 22 11 99
�������
3 5 error
��ʾ
 ���Ƕ�����������������while(cin>>......)

*/