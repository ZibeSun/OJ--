#include<iostream>
using namespace std;
//ֱ�Ӳ�������
void StraightInsertSort(int* item, int n)
{
	for (int i = 1; i < n; i++)
	{
		for (int k = i; k > 0; k--)
		{
			if (item[k] <= item[k - 1])
			{
				int m = item[k];
				item[k] = item[k - 1];
				item[k - 1] = m;
			}
			else
				break;
		}

		//ÿ����������һ�ν��
		for (int i = 0; i < n; i++)
		{
			cout << item[i] << " ";
		}
		cout << endl;
	}
}
int main()
{
	int n;
	cin >> n;
	int* item = new int[n];
	for (int i = 0; i < n; i++)
	{
		cin >> item[i];
	}
	StraightInsertSort(item, n);
}
/*
��Ŀ����
����һ�����ݣ�ʹ��ֱ������������ݵ���������
--����Ҫ��--
��ʹ��C++ֻ��includeһ��ͷ�ļ�iostream����ʹ��C����ֻ��includeһ��ͷ�ļ�stdio
��������include���һ��ͷ�ļ����������룬��0�ִ���
������ʹ�õ������������ʵ�ֱ����Ҫ��
����
���ݸ���n��n������
���
ֱ�������ÿһ��������
��������
7 34 23 677 2 1 453 3
�������
23 34 677 2 1 453 3
23 34 677 2 1 453 3
2 23 34 677 1 453 3
1 2 23 34 677 453 3
1 2 23 34 453 677 3
1 2 3 23 34 453 677
��ʾ

*/