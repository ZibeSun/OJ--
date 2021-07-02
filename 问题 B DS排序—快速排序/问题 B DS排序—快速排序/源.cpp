#include<iostream>
using namespace std;
int getPivotkey(int* item, int low, int high)
{
	int key = item[low];
	while (low < high)
	{
		while (low < high && item[high] >= key)
		{
			high--;
		}
		if (low < high)
		{
			item[low] = item[high];
		}

		while (low < high && item[low] <= key)
		{
			low++;
		}
		if (low < high)
		{
			item[high] = item[low];
		}
	}
	item[low] = key;
	return low;
}
void QuickSort(int* item, int low, int high)
{
	if (low <= high)
	{
		int pivotkey = getPivotkey(item, low, high);
		cout << item[pivotkey] << " " << pivotkey+1 << endl;
		QuickSort(item, low, pivotkey - 1);
		QuickSort(item, pivotkey + 1, high);
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
		QuickSort(item, 0, n-1);
		cout << endl;
	}
}
/*
��Ŀ����
����һ�����ݣ��ÿ������������������
����
���Դ���t
ÿ���������Ϊ��
���ݸ���n��n������
���
��ÿ��������ݣ������������ÿ���źõ����ּ�λ�ã�λ�ô�1��ʼ������ͬ��������ݵ�����Կ��зָ���
��������
2
6 111 22 6 444 333 55
8 77 555 33 1 444 77 10 200
�������
111 4
55 3
6 1
22 2
333 5
444 6

77 4
10 2
1 1
33 3
444 7
200 6
77 5
555 8
��ʾ

*/