#include<iostream>
using namespace std;
//�۰��������
void BinaryInsertSort(int* item, int n)
{
	int temp;
	for (int i = 1; i < n; i++)
	{
		temp = item[i];
		int low = 0;
		int high = i-1;
		int mid;
		while (low <= high)
		{
			mid = (low + high) / 2;
			if (temp > item[mid])
				high = mid - 1;
			else
				low = mid + 1;
		}
		int j;
		for (j = i - 1; j >= high + 1; j--)
			item[j + 1] = item[j];
		item[j + 1] = temp;

		for (int k = 0; k < n; k++)
		{
			cout << item[k] << " ";
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
		BinaryInsertSort(item, n);
		cout << endl;
	}
}
/*
��Ŀ����
����һ���������У�ʹ���۰���������㷨���н�������
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
8
30 13 70 85 39 42 6 20
�������
111 22 6 444 333
111 22 6 444 333
444 111 22 6 333
444 333 111 22 6

30 13 70 85 39 42 6 20
70 30 13 85 39 42 6 20
85 70 30 13 39 42 6 20
85 70 39 30 13 42 6 20
85 70 42 39 30 13 6 20
85 70 42 39 30 13 6 20
85 70 42 39 30 20 13 6

��ʾ

*/