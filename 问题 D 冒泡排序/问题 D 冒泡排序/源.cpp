#include<iostream>
using namespace std;
void BubbleSort(int* item,int n)
{
	int num = 0;
	for (int i = 0; i < n; i++)
	{
		for (int k = 0; k < n-1; k++)
		{
			if (item[k] >= item[k + 1])
			{
				int m = item[k];
				item[k] = item[k + 1];
				item[k + 1] = m;

				num++;   //��������+1
			}
		}
	}
	/*for (int i = 0; i < n; i++)
	{
		cout << item[i] << " ";
	}
	cout << endl;*/
	cout << num << endl;
}
int main()
{
	int n;
	while (cin >> n)
	{
		int* item = new int[n];
		for (int i = 0; i < n; i++)
		{
			cin >> item[i];
		}
		BubbleSort(item, n);
	}
}
/*
��Ŀ����
����һ��������0��n-1��һ�ε����飬��ʹ��ð����������Ϊ������������Ҫ���ж��ٴν���
����
���������ж��飬
ÿ����������ɣ���һ�а���������n��n <= 5000��; ��һ�а�����0��n-1��n�����������С�
���
����ÿ��������ݣ�
�����������
��������
10
1 3 6 9 0 8 5 7 4 2
�������
22
��ʾ

*/