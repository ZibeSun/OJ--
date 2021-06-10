#include<iostream>
using namespace std;
//ϣ������
void ShellSort(int* item,int n)
{
	int gap = n / 2;
	while (gap >= 1)
	{
		int t = gap;
		int pos = 0;
		while (t--)
		{
			for (int i = pos; i < n; i+=gap)
			{
				for (int k = pos; k < n - gap; k+=gap)
				{
					if (item[k] <= item[k + gap])
					{
						int m = item[k];
						item[k] = item[k + gap];
						item[k + gap] = m;
					}
				}
			}
			pos++;
		}

		//ÿ�����������һ�ν��
		for (int i = 0; i < n; i++)
		{
			cout << item[i] << " ";
		}
		cout << endl;

		gap = gap / 2;
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
		ShellSort(item, n);
		cout << endl;
	}
}
/*
��Ŀ����
����һ���������У�ʹ��ϣ�������㷨���н�������
���gapʹ�����г���ѭ����2ֱ��1
����
��һ������t����ʾ��t������ʾ��
�ڶ�������n����ʾ��һ��ʾ����n������(n>1)
����������n�����ݣ�����������������֮���ÿո����
�Դ�����
���
��ÿ��������ݣ����ÿ������������ͬ��������ݼ��ÿ��зָ���
��������
2
6
111 22 6 444 333 55
8
77 555 33 1 444 77 666 2222
�������
444 333 55 111 22 6
444 333 111 55 22 6

444 555 666 2222 77 77 33 1
666 2222 444 555 77 77 33 1
2222 666 555 444 77 77 33 1
��ʾ

*/