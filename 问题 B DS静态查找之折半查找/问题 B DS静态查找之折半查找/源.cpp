#include<iostream>
using namespace std;
//�۰���Һ���
//���ҳɹ��򷵻�Ԫ���������е�λ��
//����ʧ���򷵻�0
int Binary_Search(int* item,int n,int key)
{
	int low = 1;
	int high = n;
	int mid = (n + 1) / 2;
	while (low <= high)
	{
		if (key < item[mid])
		{
			high = mid - 1;
			mid = (low + high) / 2;
		}
		else if (key > item[mid])
		{
			low = mid + 1;
			mid = (low + high) / 2;
		}
		else if(key==item[mid])
		{
			return mid;
		}
	}
	return 0;
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
			if (Binary_Search(item, n, key) != 0)
				cout << Binary_Search(item, n, key) << endl;
			else
				cout << "error" << endl;
		}
	}
}
/*
��Ŀ����
����һ�����к�Ҫ���ҵ���ֵ���ҳ���ֵ�ڶ����е�λ�ã�����λ�ô�1��ʼ
Ҫ��ʹ���۰�����㷨
����
��һ������n����ʾ������n������
�ڶ�������n�����ݣ���������������С�����ÿո����
����������t����ʾ��t��Ҫ���ҵ���ֵ
������������t����ֵ������t��
1 <= n, t <= 10000
���
ÿ�����һ��Ҫ���ҵ���ֵ�ڶ��е�λ�ã�������Ҳ��ɹ�������ַ���error
��������
8 11 22 33 44 55 66 77 88 3 22 88 99
�������
2 8 error
��ʾ
���Ƕ�����������������while(cin>>......)

*/