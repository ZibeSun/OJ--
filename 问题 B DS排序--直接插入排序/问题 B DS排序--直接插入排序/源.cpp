#include<iostream>
using namespace std;
//ֱ�Ӳ�������
void StraightInsertSort(int* item,int n)
{
	for (int i = 1; i < n; i++)
	{
		for (int k = i; k > 0; k--)
		{
			if (item[k] <= item[k-1])
			{
				int m = item[k];
				item[k] = item[k-1];
				item[k-1] = m;
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
	int t;
	cin >> t;
	int n;
	while (t--)
	{
		cin >> n;
		int* item = new int[n];
		for (int i = 0; i < n; i++)
		{
			cin >> item[i];
		}
		StraightInsertSort(item, n);
		cout << endl;
	}
}
/*
��Ŀ����
����һ���������У�ʹ��ֱ�Ӳ��������㷨���н�������
����
��һ������t����ʾ��t������ʾ��
�ڶ�������n����ʾ��һ��ʾ����n������(n>1)
����������n�����ݣ�����������������֮���ÿո����
�Դ�����
���
��ÿ��������ݣ����ÿ������������ͬ��������ݼ��ÿ��зָ���
��������
2
5
111 22 6 444 333
6
21 25 49 25 16 8
�������
22 111 6 444 333
6 22 111 444 333
6 22 111 444 333
6 22 111 333 444

21 25 49 25 16 8
21 25 49 25 16 8
21 25 25 49 16 8
16 21 25 25 49 8
8 16 21 25 25 49
��ʾ

*/